#include "myDate.h"

myDate::myDate()
{
	month = 5;
	day = 11;
	year = 1959;

}

myDate::myDate(int M, int D, int Y)
{
	int a = M;
	int b = D;
	int c = Y;
	int Jdate = GtoJ(a, b, c);
	JtoG(Jdate, a, b, c);
	if (a == M && b == D && c == Y)
	{
		month = M;
		day = D;
		year = Y;
	}
	else
	{
		month = 5;
		day = 11;
		year = 1959;
	}
}

string myDate::display()
{
	string date;
	stringstream ss;
	if (month == 1)
	{
		//cout << "January " << day << ", " << year<<" ";
		 ss << "January " << day << ", " << year;
		 date = ss.str();
	}
	else if (month == 2)
	{
		ss << "February " << day << ", " << year;
		date = ss.str();
	}
	else if (month == 3)
	{
		ss << "March " << day << ", " << year;
		date = ss.str();
	}
	else if (month == 4)
	{
		ss << "April " << day << ", " << year;
		date = ss.str();
	}
	else if (month == 5)
	{
		ss << "May " << day << ", " << year;
		date = ss.str();
	}
	else if (month == 6)
	{
		ss << "June " << day << ", " << year;
		date = ss.str();
	}
	else if (month == 7)
	{
		ss << "July " << day << ", " << year;
		date = ss.str();
	}
	else if (month == 8)
	{
		ss << "August " << day << ", " << year;
		date = ss.str();
	}
	else if (month == 9)
	{
		ss << "September " << day << ", " << year;
		date = ss.str();
	}
	else if (month == 10)
	{
		ss << "October " << day << ", " << year;
		date = ss.str();
	}
	else if (month == 11)
	{
		ss << "November " << day << ", " << year;
		date = ss.str();
	}
	else
	{
		ss << "December " << day << ", " << year;
		date = ss.str();
	}
	return date;
}

void myDate::incrDate(int N)
{
	int JDate = GtoJ(month, day, year);
	JDate = JDate + N;
	JtoG(JDate, month, day, year);
}

void myDate::decrDate(int N)
{
	int JDate = GtoJ(month, day, year);
	JDate = JDate - N;
	JtoG(JDate, month, day, year);
}

int myDate::daysBetween(myDate D)
{
	int JDate1 = GtoJ(month, day, year);
	int JDate2 = GtoJ(D.month, D.day, D.year);
	int days = JDate2 - JDate1;
	return days;
}

int myDate::getMonth()
{
	return month;
}

int myDate::getDay()
{
	return day;
}

int myDate::getYear()
{
	return year;
}

int myDate::dayOfYear()
{
	int JDate = GtoJ(month, day, year);
	int yrStrt = GtoJ(1, 1, year);
	int offset = JDate - yrStrt + 1;
	return offset;
}

string myDate::dayOfWeek() {
	int JDate = GtoJ(month, day, year);
	if (JDate % 7 == 0) 
	{
		return "Monday";
	}
	else if(JDate % 7 == 1)
	{
		return "Tuesday";
	}
	else if (JDate % 7 == 2)
	{
		return "Wednesday";
	}
	else if (JDate % 7 == 3)
	{
		return "Thursday";
	}
	else if (JDate % 7 == 4)
	{
		return "Friday";
	}
	else if (JDate % 7 == 5)
	{
		return "Saturday";
	}
	else
	{
		return "Sunday";
	}
}


void myDate::JtoG(int JD, int &M, int &D, int &Y)
{
	int I, J, K, L, N;

	L = JD + 68569;
	N = 4 * L / 146097;
	L = L - (146097 * N + 3) / 4;
	I = 4000 * (L + 1) / 1461001;
	L = L - 1461 * I / 4 + 31;
	J = 80 * L / 2447;
	K = L - 2447 * J / 80;
	L = J / 11;
	J = J + 2 - 12 * L;
	I = 100 * (N - 49) + I + L;

	Y = I;
	M = J;
	D = K;
}

double myDate::GtoJ(int M, int D, int Y)
{
	int I = Y;
	int J = M;
	int K = D;
	int JD = K - 32075 + 1461 * (I + 4800 + (J - 14) / 12)
		/ 4 + 367 * (J - 2 - (J - 14) / 12 * 12) / 12 - 3 
		* ((I + 4900 + (J - 14) / 12) / 100) / 4;
	return JD;
}

void myDate::setDate(int julian)
{
	JtoG(julian, month, day, year);
}

int myDate::getJulian()
{
	return GtoJ(month, day, year);
}




