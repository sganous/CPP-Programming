
#include <iostream>
#include <string>
using namespace std;

class upDate
{
private:
	
	int *dptr;
	static int count;
	void JtoG(int JD, int &, int &, int &);
	double GtoJ(int , int , int );

public:
	upDate();
	upDate(int M, int D, int Y);
	upDate(upDate&);
	~upDate();
	

	void display();
	void incrDate(int N);
	void decrDate(int N);
	int daysBetween(upDate D);
	int getMonth();
	int getDay();
	int getYear();
	int dayOfYear();
	string dayOfWeek();
	void setDate(int,int,int);
	void setDate(int);
	int julian();

	upDate operator+(int);
	friend upDate operator+(int, upDate);
	upDate operator-(int);
	int operator-(upDate);
	static int GetDateCount();
	friend ostream &operator<<(ostream&, upDate);
	upDate operator++(int);
	upDate operator++();
	upDate operator--(int);
	upDate operator--();
	bool operator==(upDate);
	bool operator<(upDate);
	bool operator>(upDate);
	void operator=(upDate&);
	
};