#pragma once


#include "Student.h"
#include "Doctor.h"

//============================= FUNCTIONS PROTOTYPES =========================================
//Flags for the login proccess

extern deque <shared_ptr<Student> > STUDENTS;

extern deque <shared_ptr<Course> > COURSES;
extern deque <shared_ptr<Doctor> > DOCTORS;
extern int wait;
extern int status;
extern int soz ;


extern vector <string> doctors;
extern vector <string> students;
extern vector <string> studentsID;

//mp
//Main Menu function
void mainMenu();
//Login function
void login(vector<string>& s = students, vector<string>& d = doctors, int trials = 2, string message = "");
//Signup function
void signUp();
//Function to take unbuffered input
void unbufInput(bool condition = true, char choice = 'b');
//Time delay function
void delay(int s);
//Function to display line of dashes
void L(int t = 0);
//sp
//Function to display Student's menu
void studentMenu(shared_ptr<Student>& s);
//Function to display the list of courses of a student
void coursesList(shared_ptr<Student>& S);
//Function to register a course for the student (tmep_
void registerCourse(shared_ptr<Student>& s);

//Function to display info for a course for student
void stViewCourse(shared_ptr<Course>& c, shared_ptr<Student>& S);
//Function to auto add courses by semester
void autoAdd(shared_ptr<Course>& C);
//dp
//Function to display Doctor's menu
void courseGrades(shared_ptr<Course>& c);
void doctorMenu(shared_ptr<Doctor>& d);
//Function to dispaly the list of courses of a doctor
void coursesList(shared_ptr<Doctor>& D);
//Function to create a course by doctor
void addToDr(shared_ptr<Doctor>& d);
void notAutoAdd(shared_ptr<Course>& C);
void edit_pre(shared_ptr<Course>& cc);


void create(shared_ptr<Doctor>& d);

void addAssignmentToCourse(shared_ptr<Doctor>& d, shared_ptr<Course>& c);
void listAss(shared_ptr<Doctor>& d, shared_ptr<Course>& c);
void listAss(shared_ptr<Student>& s, shared_ptr<Course>& c);
//Function to display info for a course for doctor
void drViewCourse(shared_ptr<Course>& c, shared_ptr<Doctor>& D);
void bye();
void makeSubmission(shared_ptr<Student>& s, shared_ptr<Assignment>& as);
void viewAss(shared_ptr<Assignment>& as, shared_ptr<Doctor>& d);
void viewComments(shared_ptr <Submission>& sub);
void viewSub(shared_ptr <pair<shared_ptr <Student> const, shared_ptr<Submission> > > temp, shared_ptr<Assignment>& as, shared_ptr<Doctor>& d);
void subList(shared_ptr<Assignment>& as, shared_ptr<Doctor>& d);

void viewSub(shared_ptr<Submission>& sub, shared_ptr<Student>& s, shared_ptr<Course>& c);

void viewAss(shared_ptr<Assignment>& as, shared_ptr<Doctor>& d);

void viewAss(shared_ptr<Assignment>& as, shared_ptr <Student>& s, shared_ptr<Course>& c);

void loadC(shared_ptr<Student>& x);
void gradeList(shared_ptr<Student>& s);