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

#include "Student.h"
#include "Course.h"
#include "Submission.h"

struct Doctor;


extern deque <shared_ptr<Student> > STUDENTS;




struct Assignment {
	string name;
	double fullMark;
	string deadLine;

	shared_ptr < Course >crs;
	shared_ptr < Doctor > dr;
	deque <string> desc;

	deque < double > marks;
	map <shared_ptr <Student>, shared_ptr<Submission> > subs;

	Assignment(string n, double fM, string dL, deque <string>ds) {

		name = n; fullMark = fM, deadLine = dL; desc = ds;


	}

	Assignment(string n, double fM, string dL, shared_ptr < Course >  c, shared_ptr < Doctor >d, deque <string>ds) {

		name = n; fullMark = fM, deadLine = dL; crs = c; dr = d; desc = ds;

	}

	~Assignment() {	};


	bool operator < (const Assignment& b) const
	{
		return deadLine < b.deadLine;
	}
};


