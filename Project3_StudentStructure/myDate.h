
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class myDate
{
private:
	int month;
	int day;
	int year;
	void JtoG(int JD, int &, int &, int &);
	double GtoJ(int , int , int );

public:
	myDate();
	myDate(int M, int D, int Y);
	string display();
	void incrDate(int N);
	void decrDate(int N);
	int daysBetween(myDate D);
	int getMonth();
	int getDay();
	int getYear();
	int dayOfYear();
	string dayOfWeek();
	void setDate(int);
	int getJulian();
};