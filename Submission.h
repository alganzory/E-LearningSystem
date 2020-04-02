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


struct Assignment;



struct Submission {
	string name;
	shared_ptr <Assignment> asi;
	shared_ptr <Student> std;
	string graded;
	double mark;
	deque <string > ans;
	deque <deque <string > > comments;


	Submission(string n, shared_ptr<Assignment> a, deque <string > ba) {
		name = n; asi = a;   ans = ba;
		graded = "Not graded";
	}

	~Submission() {}

	void markSubmission(double m) {
		mark = m;
	}

	void addComment(deque < string >& c) {
		comments.push_back(c);
	}
};




