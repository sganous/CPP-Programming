#include "MemoryManager.h"

#include <iomanip>
#include <iostream>
using namespace std;

namespace MemoryManager
{
	// IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT
	//
	// This is the only static memory that you may use, no other global variables
	// may be created, if you need to save data make it fit in MM_pool
	//
	// IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT


	const int MM_POOL_SIZE = 65536;
	char MM_pool[MM_POOL_SIZE];

	// I have provided this tool for your use
	void memView(int start, int end)
	{
		const unsigned int SHIFT = 8;
		const unsigned int MASK = 1 << SHIFT - 1;

		unsigned int value;	// used to facilitate bit shifting and masking

		cout << "         Pool                     Unsignd  Unsigned " << endl;
		cout << "Mem Add  indx   bits   chr ASCII#  short      int    " << endl;
		cout << "-------- ---- -------- --- ------ ------- ------------" << endl;

		for (int i = start; i <= end; i++)
		{
			cout << (long*)(MM_pool + i) << ':';	// the actual address in hexadecimal
			cout << '[' << setw(2) << i << ']';		// the index into MM_pool

			value = MM_pool[i];
			cout << " ";
			for (int j = 1; j <= SHIFT; j++)	// the bit sequence for this byte (8 bits)
			{
				cout << ((value & MASK) ? '1' : '0');
				value <<= 1;
			}
			cout << " ";

			cout << '|' << *(char*)(MM_pool + i) << "| (";		// the ASCII character of the 8 bits (1 byte)
			cout << setw(4) << ((int)(*((unsigned char*)(MM_pool + i)))) << ")";	// the ASCII number of the character

			cout << " (" << setw(5) << (*(unsigned short*)(MM_pool + i)) << ")";	// the unsigned short value of 16 bits (2 bytes)
			cout << " (" << setw(10) << (*(unsigned int*)(MM_pool + i)) << ")";	// the unsigned int value of 32 bits (4 bytes)

			cout << endl;
		}
	}
	
	// Initialize set up any data needed to manage the memory pool
	void initializeMemoryManager(void)
	{
		MM_pool[0] = 6;
		MM_pool[2] = 0;
		MM_pool[4] = 0;
	}

	
	// return a pointer inside the memory pool
	// If no chunk can accommodate aSize call onOutOfMemory() - still 
	void* allocate(int aSize)
	{
		if (freeMemory() < (aSize + 6))
		{
			onOutOfMemory();
		}
		else
		{
			int nextAvailableAddress = MM_pool[0];
			MM_pool[nextAvailableAddress] = aSize;
			MM_pool[nextAvailableAddress + 2] = MM_pool[2];
			if (MM_pool[2] > 0)
			{
				MM_pool[MM_pool[2] + 4] = nextAvailableAddress;
			}
			MM_pool[2] = nextAvailableAddress;
			MM_pool[0] += (aSize + 6);

			return (void*)nextAvailableAddress;
		}
	}
	
	// Free up a chunk previously allocated
	void deallocate(void* aPointer)
	{
		
		//Change the surrounding nodes
		int nextNode = MM_pool[(int)aPointer + 2];
		int prevNode = MM_pool[(int)aPointer + 4];
		MM_pool[prevNode + 2] = nextNode;
		if (0 != nextNode) 
		{
			MM_pool[nextNode + 4] = prevNode;
		}
		//Change the current node
		MM_pool[(int)aPointer + 2] = MM_pool[4];
		MM_pool[(int)aPointer + 4] = 0;
		//Change Menu Index
		if (MM_pool[4] > 0)
		{
			MM_pool[MM_pool[4] + 4] = (int)aPointer;
		}
		MM_pool[4] = (int)aPointer;
		
	}
	
	//---
	//--- support routines
	//--- 
	
	// Will scan the memory pool and return the total free space remaining
	int freeMemory(void)
	{
		return MM_POOL_SIZE - (int)MM_pool[0];
	}
	/*
	// Will scan the memory pool and return the total deallocated memory
	int usedMemory(void)
	{
		int usedMem = 6;
		int index = (int)MM_pool[4];
		do
		{
			usedMem += (((int)MM_pool[index]) + 6);
			index = (int)MM_pool[index + 2];
		} while (index != 0);

		return usedMem;
	}
	/*
	// Will scan the memory pool and return the total in use memory
	int inUseMemory(void)
	{
		// your solution goes here
	}
	*/
}
