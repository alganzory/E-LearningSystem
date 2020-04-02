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


extern deque <shared_ptr<Course> > COURSES;

struct Doctor {
	// Members
	//=======================================================================================
	string name;
	string username;
	deque <shared_ptr<Course> > courses; // a vector to store the courses the doctor is teaching
	//=======================================================================================

	// Constructor and deconstructor
	//=======================================================================================

	Doctor(string n, string u) {
		name = n; username = u;
		for (int i = 0; i < COURSES.size(); i++) {
			if (COURSES[i]->Dr == name) courses.emplace_back(COURSES[i]);
		}

	}
	~Doctor() { }
	//=======================================================================================

	//Methods
	//=======================================================================================
	//---------------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------------
	void removeCourse(string name) {
		auto pred = [name](shared_ptr <Course> course) {
			return course->name == name;
		};
		auto it = find_if(courses.begin(), courses.end(), pred);
		courses.erase(it);
	}
	//---------------------------------------------------------------------------------------


	//Overloaded operators
	//=======================================================================================
	bool operator == (const Doctor& b)  const {
		return username == b.username;
	}                                                  //to recognise same doctor by username

	bool operator < (const Doctor& b) const {
		if (name != name) return name < b.name;
		else return username < b.username;
	}


};
