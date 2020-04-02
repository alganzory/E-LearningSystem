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

#include "functions.h"

deque <shared_ptr<Course> > COURSES{
	make_shared<Course>(Course("Programming Technique 2", "SECOP1234" , "Nor Bahia", 2)),
	make_shared<Course>(Course("Programming Technique 1","SECR1013","lizawati bint Yusof", 1)),
	make_shared<Course>(Course("Digital Logic", "SECF1050", "Zuriahati" , 1)),
	make_shared<Course>(Course("Discrete Structure", "SECI1010", "Nor Haizan", 1)),
	make_shared<Course>(Course("Computational Mathematics", "SEC2019", "Nor Haizan" , 2)),
	make_shared<Course>(Course("Mobile Apps", "SEC2019", "Mohamed Alganzory" , 1))
};


deque <shared_ptr<Student> > STUDENTS = {
	make_shared<Student> (Student ("Mohamedo Alganzoro", "A19EC4015", "Mido" , 1)),
	make_shared<Student> (Student("Ahmedo Yousif", "A19EC4003","Ahmedo",2))
};


deque <shared_ptr <Doctor> > DOCTORS = {
	make_shared <Doctor> (Doctor ("Mohamed Alganzory", "Mohamed")),
	make_shared <Doctor> (Doctor("Ahmed Yousif", "Ahmed"))
};


//============================= MAIN FUNCTION ==================================================

int main() {

	//Loading up some example data for assignments for an example course

	COURSES[5]->assignments = {
		make_shared<Assignment>(Assignment("Test1", 10, "20/5/2020" ,  {"This is a cool course" , "Please study "})),
		make_shared<Assignment>(Assignment("Test2", 20, "2/5/2020" ,  {"Thie" , "Pleasudy "})),
		make_shared<Assignment>(Assignment("Test3", 30, "20/5/0" ,  {"Taaaa " , "aaaady "}))

	};
	

	mainMenu();

	system("PAUSE");

}

