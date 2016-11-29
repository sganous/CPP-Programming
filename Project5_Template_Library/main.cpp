#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

void print500(vector<int>);
int getMode(vector<int>);
void printGraph(vector<int>);

int main()
{
	/* Populate the vector array with 10,000 random integers */
	vector<int> vint;
	srand(time(NULL));
	for (int i = 0; i < 10000; i++)
	{
		vint.push_back(rand() % 100 + 1);
	}

	/* Print the first 500 integers of the unsorted array */
	cout << "First 500 numbers in the unsorted array: " << endl;
	print500(vint);
	cout << '\n' <<endl;

	/* Sort the vector, samllest to largest */
	cout << "First 500 numbers in the sorted array: " << endl;
	sort(vint.begin(), vint.end());
	print500(vint);
	cout << '\n' << endl;

	/* Print the sum/avg/mode of all the numbers */
	double sum = accumulate(vint.begin(), vint.end(), 0);
	double avg = sum / 10000;
	int mode = getMode(vint);
	cout << "Total Sum: " << sum << endl;
	cout << "Average: " << avg << endl;
	cout << "Mode: " << mode <<	'\n'<<endl;

	/* Print a graph of the number frequency */
	printGraph(vint);

	system("pause");
	return 0;
}

void print500(vector<int> v1)
{
	int i = 0;
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << setw(4) << *it << ((++i % 15) ? ',' : '\n');
		if (i >= 500)break;
	}
}

int getMode(vector<int> v)
{
	int count1 = 0;
	int count2 = 0;
	int index = 0;
	int rv;
	vector<int>::iterator a = v.begin();
	vector<int>::iterator z = v.end();
	vector<int>::iterator it;
	for (it = a; it != v.end(); it++)
	{
		if (it != z - 1 && (*it != *(it + 1)))
		{
			if (count1 > count2) {
				count2 = count1;
				index = *it;
			}
			count1 = 0;
		}
		else if (it == z - 1)
		{
			if (count1 > count2) {
				count2 = count1;
				index = *it;
			}
			count1 = 0;
		}
		else
		{
			count1++;
		}
	}
	return index;
}

void printGraph(vector<int> v)
{
	int count = 0;
	int index = 0;
	vector<int>::iterator a = v.begin();
	vector<int>::iterator z = v.end();
	vector<int>::iterator it;
		for (it = a; it != v.end(); it++)
		{
			if ( it != z-1 && (*it != *(it+1))) {
				cout <<setw(3)<< *it << ':' <<setw(3)<< count;
				for (int i = 0; i < count; i = i + 2)
				{
					cout << '-';
				}
				cout << endl;
				count = 0;
			}
			else if (it == z - 1)
			{
				cout << setw(3) << *it << ':' << setw(3) << count;
				for (int i = 0; i < count; i = i + 2)
				{
					cout << '-';
				}
				cout << '\n' << endl;
				count = 0;
			}
			count++;
		}
}
