#include "upDate.h"
/*******************************CONSTRUCTORS**********************/
/*Default Constructor*/
upDate::upDate()
{
	dptr = new int[3];	//Allocate memory for the object
	dptr[0] = 5;
	dptr[1] = 11;
	dptr[2] = 1959;
	count++;	
}

/*Constructor Accepting month, day, year*/
upDate::upDate(int M, int D, int Y)
{
	dptr = new int[3];
	int a = M;
	int b = D;
	int c = Y;
	int Jdate = GtoJ(a, b, c);
	JtoG(Jdate, a, b, c);
	if (a == M && b == D && c == Y)
	{
		dptr[0] = M;
		dptr[1] = D;
		dptr[2] = Y;
	}
	else
	{
		dptr[0] = 5;
		dptr[1] = 11;
		dptr[2] = 1959;
	}
	
	count++;
}

/*Constructor that accepts another upDate object*/
upDate::upDate(upDate &date)
{
	dptr = new int[3];	//Allocate memory for the object
	dptr[0] = date.getMonth();
	dptr[1] = date.getDay();
	dptr[2] = date.getYear();
	count++;
}

/* Destructor */
upDate::~upDate()
{
	count--;
	delete[]dptr;
}
/****************************OBJECT METHODS*****************************/

/* Display method performs a cout ex: "January 1, 1995" */
void upDate::display()
{
	if (dptr[0] == 1)
	{
		cout << "January " << dptr[1] << ", " << dptr[2] <<" ";
	}
	else if (dptr[0] == 2)
	{
		cout << "February " << dptr[1] << ", " << dptr[2] <<" ";
	}
	else if (dptr[0] == 3)
	{
		cout << "March " << dptr[1] << ", " << dptr[2] << " ";
	}
	else if (dptr[0] == 4)
	{
		cout << "April " << dptr[1] << ", " << dptr[2] << " ";
	}
	else if (dptr[0] == 5)
	{
		cout << "May " << dptr[1] << ", " << dptr[2] << " ";
	}
	else if (dptr[0] == 6)
	{
		cout << "June " << dptr[1] << ", " << dptr[2] << " ";
	}
	else if (dptr[0] == 7)
	{
		cout << "July " << dptr[1] << ", " << dptr[2] << " ";
	}
	else if (dptr[0] == 8)
	{
		cout << "August " << dptr[1] << ", " << dptr[2] << " ";
	}
	else if (dptr[0] == 9)
	{
		cout << "September " << dptr[1] << ", " << dptr[2] << " ";
	}
	else if (dptr[0] == 10)
	{
		cout << "October " << dptr[1] << ", " << dptr[2] << " ";
	}
	else if (dptr[0] == 11)
	{
		cout << "November " << dptr[1] << ", " << dptr[2] << " ";
	}
	else
	{
		cout << "December " << dptr[1] << ", " << dptr[2] << " ";
	}

}

/* Increase upDate by N days*/
void upDate::incrDate(int N)
{
	int JDate = GtoJ(dptr[0], dptr[1], dptr[2]);
	JDate = JDate + N;
	JtoG(JDate, dptr[0], dptr[1], dptr[2]);
}

/* Decrease upDate by N days*/
void upDate::decrDate(int N)
{
	int JDate = GtoJ(dptr[0], dptr[1], dptr[2]);
	JDate = JDate - N;
	JtoG(JDate, dptr[0], dptr[1], dptr[2]);
}

/* Returns days between two upDate objects*/
int upDate::daysBetween(upDate D)
{
	int JDate1 = GtoJ(dptr[0], dptr[1], dptr[2]);
	int JDate2 = GtoJ(D.dptr[0], D.dptr[1], D.dptr[2]);
	int days = JDate2 - JDate1;
	return days;
}

/* Returns object's current month */
int upDate::getMonth()
{
	return dptr[0];
}

/* Returns object's current day */
int upDate::getDay()
{
	return dptr[1];
}

/* Returns objects current year */
int upDate::getYear()
{
	return dptr[2];
}

/* Returns the day of the current year. ex: 165 */
int upDate::dayOfYear()
{
	int JDate = GtoJ(dptr[0], dptr[1], dptr[2]);
	int yrStrt = GtoJ(1, 1, dptr[2]);
	int offset = JDate - yrStrt + 1;
	return offset;
}

/* Returns the day of the week. ex: "Monday"*/
string upDate::dayOfWeek() {
	int JDate = GtoJ(dptr[0], dptr[1], dptr[2]);
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

/* Changes the date of the object according to the Julian Date */
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

/* Converts Gregorian date into a Julian value */
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

/* Sets the current date to the corresponding M, D, Y values */
void upDate::setDate(int M, int D, int Y)
{
	int a = M;
	int b = D;
	int c = Y;
	int Jdate = GtoJ(a, b, c);
	JtoG(Jdate, a, b, c);
	if (a == M && b == D && c == Y)
	{
		dptr[0] = M;
		dptr[1] = D;
		dptr[2] = Y;
	}
	else
	{
		dptr[0] = 5;
		dptr[1] = 11;
		dptr[2] = 1959;
	}
}

/* Sets the current date to the corresponding Julian value */
void upDate::setDate(int JD)
{
	JtoG(JD, dptr[0], dptr[1], dptr[2]);
}

/* Returns Julian value corresponding to current date */
int upDate::julian()
{
	return GtoJ(dptr[0], dptr[1], dptr[2]);
}

/* Handles upDate + integer operations EX: D1 + 5 */
upDate upDate::operator+(int value)
{
	upDate temp(*this);
	//int JD = GtoJ(month, day, year);
	//JD += value;
	//JtoG(JD, temp.month, temp.day, temp.year);
	temp.incrDate(value);
	return temp;
}

/* Handles integer + upDate operations EX: 5 + D1 */
upDate operator+(int value, upDate date)
{
	upDate temp = date;
	//int JD = temp.julian();
	//JD += value;
	//temp.setDate(JD);
	temp.incrDate(value);
	return temp;
}

/* Handles integer - upDate operations EX: 5 - D1 */
upDate upDate::operator-(int value)
{
	upDate temp(*this);
	//int JD = GtoJ(month, day, year);
	//JD -= value;
	//JtoG(JD, temp.month, temp.day, temp.year);
	temp.decrDate(value);
	return temp;
}

/* Handles upDate - upDate operations EX: D1 - D2 */
int upDate::operator-(upDate date)
{
	int JD = GtoJ(dptr[0], dptr[1], dptr[2]);
	JD -= date.julian();
	return JD;
}

/* Returns the count of existing objects */
int upDate::GetDateCount()
{
	return count;
}

/* Handles cout operations EX: cout<<D1 */
ostream &operator<<(ostream &out, upDate date)
{
	out << date.dptr[0];
	out << '/';
	out << date.dptr[1];
	out << '/';
	out << date.dptr[2];
	return out;
}

/* Handles upDate++ operations EX: D1++ */
upDate upDate::operator++(int unused)
{
	upDate temp(*this);
	this->incrDate(1);
	return temp;
}


/* Handles ++upDate operations EX: ++D1 */
upDate upDate::operator++()
{
	this->incrDate(1);
	return *this;
}

/* Handles upDate-- operations EX: D1-- */
upDate upDate::operator--(int unused)
{
	upDate temp(*this);
	this->decrDate(1);
	return temp;
}

/* Handles --upDate operations EX: --D1 */
upDate upDate::operator--()
{
	this->decrDate(1);
	return *this;
}

/* Handles upDate == upDate operation EX: D1 == D2 */
bool upDate::operator==(upDate date)
{
	if (this->julian() == date.julian())
	{
		return true;
	}
	else
	{
		return false;
	}
}

/* Handles upDate < upDate operation EX: D1 < D2 */
bool upDate::operator<(upDate date)
{
	if (this->julian() < date.julian())
	{
		return true;
	}
	else
	{
		return false;
	}
}

/* Handles upDate > upDate operation EX: D1 > D2*/
bool upDate::operator>(upDate date)
{
	if (this->julian() > date.julian())
	{
		return true;
	}
	else
	{
		return false;
	}
}

/* Handles upDate = upDate operation EX: D1 = D2 */
void upDate::operator=(upDate &date)
{
	dptr = new int[3];	//Allocate memory for the object
	dptr[0] = date.getMonth();
	dptr[1] = date.getDay();
	dptr[2] = date.getYear();
	count++;
}

/* Initialize Counter Variable */
int upDate::count = 0;




