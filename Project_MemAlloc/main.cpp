#include "MemoryManager.h"
#include<iostream>
#include<stdlib.h>
using namespace MemoryManager;

int main()
{
	initializeMemoryManager();
	int* iptr = (int*)allocate(4);
	char* cptr = (char*)allocate(2);
	char* cptr2 = (char*)allocate(6);
	char* cptr3 = (char*)allocate(4);

	//deallocate(cptr);
	//deallocate(iptr);
	//deallocate(cptr3);
	//memView(0, 50);
	//std::cout << usedMemory();
	system("pause");
	return 0;

}