#include <iostream>
#include <algorithm>
#include <cstring>	
#include <string>
#include <cstdlib>
#include <iomanip>
#include "myDate.h"
using namespace std;

struct Student
{
	char name[20];
	int studentID;
	char grade;
	myDate birthday;
	string homeTown;
};

bool sortByID(const Student *start,const Student *end) { return start->studentID < end->studentID; }
bool sortByBday(Student *start, Student *end) { return start->birthday.getJulian() < end->birthday.getJulian(); }
bool sortByName(Student *start, Student *end) { return (strcmp(start->name,end->name) < 0); }
bool sortByGrade(Student *start, Student *end) { return start->grade < end->grade; }
bool sortByHomeTown(Student *start, Student *end) { return start->homeTown < end->homeTown; }

void populate();
Student students[10];
//////////////////////////////////MAIN////////////////////////////////
int main()
{
	populate();
	Student *IDList[10], *bdayList[10], *nameList[10], *gradeList[10], *townList[10];
	for (int i = 0; i < 10; i++)
	{
		IDList[i] = &students[i];
		bdayList[i] = &students[i];
		nameList[i] = &students[i];
		gradeList[i] = &students[i];
		townList[i] = &students[i];
	}

	sort(IDList, IDList + 10, sortByID);
	sort(bdayList, bdayList + 10, sortByBday);
	sort(nameList, nameList + 10, sortByName);
	sort(gradeList, gradeList + 10, sortByGrade);
	sort(townList, townList + 10, sortByHomeTown);

	int choice;
	do
	{
		cout << "1) Display original list" << endl;
		cout << "2) Display list sorted by Student ID" << endl;
		cout << "3) Display list sorted by Student Age" << endl;
		cout << "4) Display list sorted by Name" << endl;
		cout << "5) Display list sorted by Grade" << endl;
		cout << "6) Display list sorted by Home Town" << endl;
		cout << "7) Exit" << endl;
		cout << endl;

		cin >> choice;
		while (choice < 1 || choice > 7)
		{
			cout << "Please select a valid option (1-7)" << endl;
			cin >> choice;
		}

		switch (choice)
		{
		case 1:
			//ORIGINAL
			cout << "ORIGINAL LIST: " << endl;
			cout << setw(15) << left << "StudentID" << setw(21) << left << "Name" << setw(20) << left << "Birthday" << setw(11) << left << "Grade" << "HomeTown" << endl;
			cout << setw(15) << left << "---------" << setw(21) << left << "----" << setw(20) << left << "--------" << setw(11) << left << "-----" << "--------" << endl;
			for (int i = 0; i < 10; i++)
			{
				cout << setw(15) << left << students[i].studentID << setw(21) << left << students[i].name << setw(20)
					<< left << students[i].birthday.display() << setw(11) << left << students[i].grade << students[i].homeTown << endl;
			}
			cout << endl;
			break;

		case 2:
			//STUDENT ID
			cout << "SORTED BY STUDENT ID: " << endl;
			cout << setw(15) << left << "StudentID" << setw(21) << left << "Name" << setw(20) << left << "Birthday" << setw(11) << left << "Grade" << "HomeTown" << endl;
			cout << setw(15) << left << "---------" << setw(21) << left << "----" << setw(20) << left << "--------" << setw(11) << left << "-----" << "--------" << endl;

			for (int i = 0; i < 10; i++)
			{
				cout << setw(15) << left << IDList[i]->studentID << setw(21) << left << IDList[i]->name << setw(20)
					<< left << IDList[i]->birthday.display() << setw(11) << left << IDList[i]->grade << IDList[i]->homeTown << endl;
			}
			cout << endl;
			break;

		case 3:
			//BIRTHDAY
			cout << "SORTED BY BIRTHDAY: " << endl;
			cout << setw(15) << left << "StudentID" << setw(21) << left << "Name" << setw(20) << left << "Birthday" << setw(11) << left << "Grade" << "HomeTown" << endl;
			cout << setw(15) << left << "---------" << setw(21) << left << "----" << setw(20) << left << "--------" << setw(11) << left << "-----" << "--------" << endl;

			for (int i = 0; i < 10; i++)
			{
				cout << setw(15) << left << bdayList[i]->studentID << setw(21) << left << bdayList[i]->name << setw(20)
					<< left << bdayList[i]->birthday.display() << setw(11) << left << bdayList[i]->grade << bdayList[i]->homeTown << endl;
			}
			cout << endl;
			break;

		case 4:
			//NAME
			cout << "SORTED BY NAME: " << endl;
			cout << setw(15) << left << "StudentID" << setw(21) << left << "Name" << setw(20) << left << "Birthday" << setw(11) << left << "Grade" << "HomeTown" << endl;
			cout << setw(15) << left << "---------" << setw(21) << left << "----" << setw(20) << left << "--------" << setw(11) << left << "-----" << "--------" << endl;

			for (int i = 0; i < 10; i++)
			{
				cout << setw(15) << left << nameList[i]->studentID << setw(21) << left << nameList[i]->name << setw(20)
					<< left << nameList[i]->birthday.display() << setw(11) << left << nameList[i]->grade << nameList[i]->homeTown << endl;
			}
			cout << endl;
			break;

		case 5:
			//GRADE
			cout << "SORTED BY GRADE: " << endl;
			cout << setw(15) << left << "StudentID" << setw(21) << left << "Name" << setw(20) << left << "Birthday" << setw(11) << left << "Grade" << "HomeTown" << endl;
			cout << setw(15) << left << "---------" << setw(21) << left << "----" << setw(20) << left << "--------" << setw(11) << left << "-----" << "--------" << endl;

			for (int i = 0; i < 10; i++)
			{
				cout << setw(15) << left << gradeList[i]->studentID << setw(21) << left << gradeList[i]->name << setw(20)
					<< left << gradeList[i]->birthday.display() << setw(11) << left << gradeList[i]->grade << gradeList[i]->homeTown << endl;
			}
			cout << endl;
			break;

		case 6:
			//HOME TOWN
			cout << "SORTED BY HOME TOWN: " << endl;
			cout << setw(15) << left << "StudentID" << setw(21) << left << "Name" << setw(20) << left << "Birthday" << setw(11) << left << "Grade" << "HomeTown" << endl;
			cout << setw(15) << left << "---------" << setw(21) << left << "----" << setw(20) << left << "--------" << setw(11) << left << "-----" << "--------" << endl;

			for (int i = 0; i < 10; i++)
			{
				cout << setw(15) << left << townList[i]->studentID << setw(21) << left << townList[i]->name << setw(20)
					<< left << townList[i]->birthday.display() << setw(11) << left << townList[i]->grade << townList[i]->homeTown << endl;
			}
			cout << endl;
			break;

		}
	} while (choice != 7);


	system("pause");
	return 0;
	
}
//////////////////////////////////////////////////////////////////////
void populate()
{
//NAMES AND HOMETOWN
	//Student 1
	strcpy_s(students[0].name, "Bruce Willis");
	students[0].homeTown = "Canada";
	//Student 2
	strcpy_s(students[1].name, "Bill Gates");
	students[1].homeTown = "United States";
	//Student 3
	strcpy_s(students[2].name, "Tom Cruise");
	students[2].homeTown = "Alaska";
	//Student 4
	strcpy_s(students[3].name, "James Cameron");
	students[3].homeTown = "Russia";
	//Student 5
	strcpy_s(students[4].name, "Will Smith");
	students[4].homeTown = "Bel Air";
	//Student 6
	strcpy_s(students[5].name, "Angelina Jolie");
	students[5].homeTown = "Florida";
	//Student 7
	strcpy_s(students[6].name, "Julia Roberts");
	students[6].homeTown = "Australia";
	//Student 8
	strcpy_s(students[7].name, "Leonardo Dicaprio");
	students[7].homeTown = "Texas";
	//Student 9
	strcpy_s(students[8].name, "Chris Rock");
	students[8].homeTown = "Idaho";
	//Student 10
	strcpy_s(students[9].name, "Harrison Ford");
	students[9].homeTown = "China";
	
//GRADE / STUDENT ID / BIRTHDAYS
	for (int i = 0; i < 10; i++)
	{
		int grade = rand() % 50 + 51;

		//GRADE LETTER CONVERSION
		if (grade >= 90)
		{
			students[i].grade = 'A';
		}
		else if (grade >= 80)
		{
			students[i].grade = 'B';
		}
		else if (grade >= 70)
		{
			students[i].grade = 'C';
		}
		else if (grade >= 60)
		{
			students[i].grade = 'D';
		}
		else
		{
			students[i].grade = 'F';
		}

		//ID VALIDATION
		int id = rand() % 8000 + 1000;
		for (int j = 0; j < 20; j++)
		{
			while (id == students[j].studentID)
			{
				id = rand() % 8000 + 1000;
				j = 0;
			}
		}
		students[i].studentID = id;

		//BIRTHDAY
		int julian = rand() % 1827 + 2448623;
		students[i].birthday.setDate(julian);

	}	
}