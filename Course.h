#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <conio.h>
#include <map>
#include <cstdlib>
#include <assert.h>
using namespace std;
using namespace this_thread;
using namespace std::chrono;

struct Student;
struct Assignment;

struct Course {
	//Members
	//===========================================================================================
	string name;
	string code;
	string Dr;
	int semester;                    // to allow automatic addition of students in this semester
	int status;
	deque <shared_ptr <Assignment> > assignments;
	vector< string > desc;
	bool described = false;
	deque <shared_ptr<Course> > pre;
	set < shared_ptr <Student> > studentCnt;
	
	Course(string n, string c, string D, int sem) {
		name = n; code = c; Dr = D; semester = sem;

	}
	Course(string n, string c, string D, int sem, deque <shared_ptr<Course> >& temp) {
		name = n; code = c; Dr = D; semester = sem; pre = temp;

	}



	~Course() {}

	//Methods
	//===========================================================================================

	//-------------------------------------------------------------------------------------------


	void drSummary() {

		cout << "Course Description: ";
		if (described) {
			cout << endl;

			for (auto& s : desc) {
				cout << s << endl;
			}
			cout << endl;
		}
		else cout << "\nNo course Description, press 'd' to add a new one" << endl << endl;

		cout << "Course Name: " << name << endl
			<< "Course Code: " << code << endl
			<< "Number of students: " << studentCnt.size() << endl
			<< "Number of assignments: " << assignments.size() << endl;
	}

	void stSummary() {
		cout << "Course Description: ";
		if (described) {
			cout << endl;
			for (auto& s : desc) {
				cout << s << endl;
			}
		}
		else cout << "\nNo course Description" << endl;
		cout << endl;
		cout << "Course Name: " << name << endl
			<< "Course Code: " << code << endl
			<< "Dr: " << Dr << endl;

	}

	void setDesc() {
		string temp;
		cout << "Press  enter twice to go back" << endl;


		while (getline(cin, temp) and temp != "") {
			desc.push_back(temp);
		}
		described = true;
	}





	//-------------------------------------------------------------------------------------------
	//void removeAssignment(string name) {
	//	auto pred = [name](const Assignment& assignment) {
	//		return assignment.name == name;
	//	};
	//	auto it = find_if(assignments.begin(), assignments.end(), pred);
	//	assignments.erase(it);
	//}

	//Overloaded operators
	//===========================================================================================
	bool operator == (shared_ptr <Course>  b) {
		return code == b->code;
	}                                                      // to recognise same course by code

};



static bool operator< (const Course& a, const Course& b)
{
	if (a.semester == b.semester) return a.name < b.name;
	else return a.semester < b.semester;
}

