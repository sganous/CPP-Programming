#include "upDate.h"

upDate::upDate()
{
	month = 5;
	day = 11;
	year = 1959;

	dptr = new int[3];
	dptr[0] = month;
	dptr[1] = day;
	dptr[2] = year;
	count++;

}

upDate::upDate(int M, int D, int Y)
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

	dptr = new int[3];
	dptr[0] = month;
	dptr[1] = day;
	dptr[2] = year;
	count++;
}

upDate::upDate(upDate &date)
{
	month = date.getMonth();
	day = date.getDay();
	year = date.getYear();

	dptr = new int[3];
	dptr[0] = month;
	dptr[1] = day;
	dptr[2] = year;
	count++;
}

void upDate::display()
{
	if (month == 1)
	{
		cout << "January " << day << ", " << year<<" ";
	}
	else if (month == 2)
	{
		cout << "February " << day << ", " << year<<" ";
	}
	else if (month == 3)
	{
		cout << "March " << day << ", " << year << " ";
	}
	else if (month == 4)
	{
		cout << "April " << day << ", " << year << " ";
	}
	else if (month == 5)
	{
		cout << "May " << day << ", " << year << " ";
	}
	else if (month == 6)
	{
		cout << "June " << day << ", " << year << " ";
	}
	else if (month == 7)
	{
		cout << "July " << day << ", " << year << " ";
	}
	else if (month == 8)
	{
		cout << "August " << day << ", " << year << " ";
	}
	else if (month == 9)
	{
		cout << "September " << day << ", " << year << " ";
	}
	else if (month == 10)
	{
		cout << "October " << day << ", " << year << " ";
	}
	else if (month == 11)
	{
		cout << "November " << day << ", " << year << " ";
	}
	else
	{
		cout << "December " << day << ", " << year << " ";
	}

}

void upDate::incrDate(int N)
{
	int JDate = GtoJ(month, day, year);
	JDate = JDate + N;
	JtoG(JDate, month, day, year);
}

void upDate::decrDate(int N)
{
	int JDate = GtoJ(month, day, year);
	JDate = JDate - N;
	JtoG(JDate, month, day, year);
}

int upDate::daysBetween(upDate D)
{
	int JDate1 = GtoJ(month, day, year);
	int JDate2 = GtoJ(D.month, D.day, D.year);
	int days = JDate2 - JDate1;
	return days;
}

int upDate::getMonth()
{
	return month;
}

int upDate::getDay()
{
	return day;
}

int upDate::getYear()
{
	return year;
}

int upDate::dayOfYear()
{
	int JDate = GtoJ(month, day, year);
	int yrStrt = GtoJ(1, 1, year);
	int offset = JDate - yrStrt + 1;
	return offset;
}

string upDate::dayOfWeek() {
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

void upDate::JtoG(int JD, int &M, int &D, int &Y)
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

double upDate::GtoJ(int M, int D, int Y)
{
	int I = Y;
	int J = M;
	int K = D;
	int JD = K - 32075 + 1461 * (I + 4800 + (J - 14) / 12)
		/ 4 + 367 * (J - 2 - (J - 14) / 12 * 12) / 12 - 3 
		* ((I + 4900 + (J - 14) / 12) / 100) / 4;
	return JD;
}

void upDate::setDate(int M, int D, int Y)
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

void upDate::setDate(int JD)
{
	JtoG(JD, month, day, year);
}

int upDate::getJulian()
{
	return GtoJ(month, day, year);
}

upDate upDate::operator+(int value)
{
	upDate temp;
	int JD = GtoJ(month, day, year);
	JD += value;
	JtoG(JD, temp.month, temp.day, temp.year);
	return temp;
}

upDate operator+(int value, upDate date)
{
	upDate temp = date;
	int JD = temp.getJulian();
	JD += value;
	temp.setDate(JD);
	return temp;
}

upDate::~upDate()
{
	count--;
	delete[]dptr;
}

upDate upDate::operator-(int value)
{
	upDate temp;
	int JD = GtoJ(month, day, year);
	JD -= value;
	JtoG(JD, temp.month, temp.day, temp.year);
	return temp;
}

int upDate::operator-(upDate date)
{
	int JD = GtoJ(month, day, year);
	JD -= date.getJulian();
	return JD;
}




