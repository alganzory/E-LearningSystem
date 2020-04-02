
#include "functions.h"
//============================= FUNCTIONS DEFINITION ===========================================


int wait = 5;
int status = -1;
int soz = 0;


vector <string> doctors = {
	"Mohamed", "m", "Ahmed","ok"
};

vector <string> students = {
	"Mido", "m", "Ahmedo","ok"
};

vector <string> studentsID = {
	"A19EC4015", "A19EC4003"
};



// mf

void mainMenu() {
	char choice;

	system("CLS");

	cout << "Main Screen" << endl; L();
	cout << "1- Login" << endl;
	delay(400);
	cout << "2- Signup" << endl;
	delay(400);
	cout << "3- Exit\n";
	delay(400);
	L();

	cout << "Your choice: ";
	cin >> choice;
	cin.ignore(1000, '\n');

	//Input validation

	if (choice == '3') {
		system("CLS");
		cout << "Thanks for yousing our program" << endl;
		delay(1500);

		return;
	}
	switch (choice) {
	case '1': {
		if (wait < 4) {
			cout << "You have attempted too many logins, please wait for a while" << endl;

			wait++;
			delay(1000);
			mainMenu();
		}
		login();
		break;
	}

	case '2':  signUp(); break;
	}
}

void login(vector<string>& s, vector<string>& d, int trials, string message) {

	system("CLS");
	cout << "Login" << endl; L();

	cout << message;

	unbufInput((status == 3 || status == 1 || status == -2));


	if (trials == 0) {
		cout << "Too many login attempts, try again later!";

		wait = 0;
		delay(1000);
		mainMenu();

		return;
	}

	string username;
	string password;
	cout << "username: ";

	getline(cin, username);
	cout << "\npassword: ";

	getline(cin, password);

	// this variable will be 1 if user not found in students
	// if it's also not found in doctors, it will be 3
	// so only if it equals 2, we say user not found
	// if user found in students with correct password then status =0;
	// if user found in students with incorrect password, then status =-2
	// if user found in doctors not students, and correct password = 2
	// if user found in doctors with incorrect passwords , =1;

	vector<string>::const_iterator st = find(s.begin(), s.end(), username);
	if (st != s.end()) {
		if (*++st == password) status = 0;
		else status = -2;
	}
	else status = 1;


	if (status == 1) {
		vector<string>::const_iterator dr = find(d.begin(), d.end(), username);
		if (dr != d.end()) {
			if (*++dr == password) status = 2;
			else status = 1;
		}
		else status = 3;
	}


	switch (status) {
	case -2:
	case 1: login(s, d, trials - 1, "Wrong Password, press any key to try again or presss b to go back: "); break;
	case 2: {
		L();
		string welcome = "Welcome Dr. ";

		for (auto& x : DOCTORS) {
			if (username == x->username) {
				for (auto v : welcome) {
					cout << v; delay(100);
				}
				for (int b = 0; b < x->name.size(); b++) {
					cout << x->name[b];
					delay(0);
				}
				cout << "!";
				delay(2000);
				doctorMenu(x);
				break;
			}
		}
		break;
	}
	case 0: {
		L();
		string welcome = "Welcome ";
		for (auto& x : STUDENTS) {
			if (username == x->username) {
				for (auto v : welcome) {
					cout << v; delay(100);
				}
				for (int b = 0; b < x->name.size(); b++) {
					cout << x->name[b];
					delay(100);
				}
				cout << "!";
				delay(2000);
				studentMenu(x);
			}
		}
		break;
	}
	case 3: login(s, d, trials - 1, "User not found, press any key to try again or presss b to go back: \n");  break;
	}
}

void signUp() {
	system("CLS");

	cout << "Signup" << endl; L();


	cout << "Choose the account type or press b to go back: " << endl << endl;
	cout << left << setw(35) << "1- Doctor Account"
		<< "2- Student Account" << endl;
	L();
	cout << "Your choice: ";
	char stroke = _getch();
	if (stroke == 'b' or stroke == 'B') mainMenu();

	if (stroke == '1') {
		system("CLS");
		cout << "Sign up for a doctor account" << endl;
		L();
		string name, username, password;
		cout << "Name: "; getline(cin, name);
		cout << "\nUsername: "; getline(cin, username);
		cout << "\nPassword: "; getline(cin, password);

		auto us = find(doctors.begin(), doctors.end(), username);
		while (us != doctors.end()) {
			L();
			cout << "An account with this username already exists!" << endl
				<< "Press 'l' to login instead or press 'b' to go back: ";
			char stroke2 = _getch();
			if (stroke2 == 'b' or stroke2 == 'B') mainMenu();
			else if (stroke2 == 'l' or stroke2 == 'L') login();
		}

		doctors.push_back(username);
		doctors.push_back(password);

		DOCTORS.emplace_back(make_shared<Doctor> (Doctor(name, username)));
		L();
		cout << "Account successfully created!" << endl;
		delay(2000);
		mainMenu();

	}

	else if (stroke == '2') {
		system("CLS");
		cout << "Sign up for a student account" << endl;
		L();

		string name, ID, username, password;
		int semester;

		cout << "Name: "; getline(cin, name);
		cout << "Student ID: "; getline(cin, ID);
		cout << "\nOngoing semester: "; cin >> semester; cin.ignore();

		cout << "\nUsername: "; getline(cin, username);
		cout << "\nPassword: "; getline(cin, password);

		auto us = find(students.begin(), students.end(), username);
		while (us != students.end() and (abs(us - students.begin()) % 2 == 0)) {
			L();
			cout << "An account with this username already exists!" << endl
				<< "Press 'l' to login instead or press 'b' to go back: ";
			char stroke2 = _getch();
			if (stroke2 == 'b' or stroke2 == 'B') mainMenu();
			else if (stroke2 == 'l' or stroke2 == 'L') login();
		}

		auto id = find(studentsID.begin(), studentsID.end(), ID);
		while (id != studentsID.end()) {
			L();
			cout << "An account with this ID already exists!" << endl
				<< "Press 'l' to login instead or press 'b' to go back: ";
			char stroke2 = _getch();
			if (stroke2 == 'b' or stroke2 == 'B') mainMenu();
			else if (stroke2 == 'l' or stroke2 == 'L') login();
		}

		students.push_back(username);
		students.push_back(password);
		studentsID.push_back(ID);

		STUDENTS.emplace_back(make_shared<Student> (Student(name, ID, username, semester)));
		loadC(STUDENTS.back());
		L();
		cout << "Account successfully created!" << endl;
		delay(2000);
		mainMenu();

	}
}

void delay(int s) {
	//sleep_until(system_clock::now() + seconds(s));
	sleep_for(std::chrono::milliseconds(s));
}

void unbufInput(bool condition, char choice) {
	char stroke;
	if (condition) {
		stroke = _getch();
		if (stroke == choice) mainMenu();
	}
}

void L(int t) {



	for (int i = 110; i != 0; i--) {
		cout << "-"; delay(t);
	}
	cout << endl;



}

//sf

void studentMenu(shared_ptr<Student>&s) {
	system("CLS");

	cout << "Press a key corresponding to your choice: " << endl;
	L();

	cout << "1- Courses list" << endl;
	delay(400);
	cout << "2- Register a course" << endl;
	delay(400);
	cout << "3- Grade list" << endl;
	delay(400);
	cout << "4- Log out" << endl;
	delay(400);

	L();
	cout << "Your choice: ";

	char stroke = _getch();
	switch (stroke) {
	case '1': coursesList(s);				break;
	case '2': registerCourse(s);		    break;
	case '3':  gradeList(s); studentMenu(s);break;
	case '4': cin.ignore(); mainMenu();	    break;
	}
}

void coursesList(shared_ptr<Student>&S) {
	system("CLS");
	char stroke;




	cout << "List of courses: " << endl; L(0);


	cout << left
		<< setw(35)
		<< "Course Name"
		<< setw(15) << "Course Code"
		<< setw(25) << "Course Doctor"
		<< setw(10) << "Number of Assignments";
	cout << endl << endl;

	int j = 0;


	for (auto& x : S->courses) {
		cout << left
			<< ++j << "- " << setw(32) <<
			x->name << setw(15) << x->code << setw(25)
			<< x->Dr << "\t\t" << setw(10) << x->assignments.size() << endl;
	}

	L();
	cout << "Select the number of the course you want to view or press 'b' to go back: ";
	stroke = _getch();



	if (stroke == 'b' || stroke == 'B') {

		studentMenu(S);
	}
	else {

		stViewCourse(S->courses[stroke - 49], S);
	}
}

void registerCourse(shared_ptr<Student>&s) {

	deque <shared_ptr <Course> > difference;
	bool flag = true;

	for (auto& x : COURSES) {

		for (auto& y : s->courses) {
			if (x->name != y->name) flag = true;
			else { flag = false; break; }

		}


		if (flag) difference.emplace_back(x);
	}

	system("CLS");

	if (difference.size() == 0) {
		cout << "There are no courses for you to register in at the moment." << endl;
		delay(3000);
		studentMenu(s);
	}


	cout << "Lists of courses you are not registered in: " << endl;
	L();
	cout << left
		<< setw(35)
		<< "Course Name"
		<< setw(15) << "Course Code"
		<< setw(20) << "Course Doctor"
		<< setw(20) << "Default Semester"
		<< "Prerequisites";
	cout << endl << endl;
	for (int i = 0; i < difference.size(); i++) {


		cout << left
			<< i + 1 << "- " << setw(32)
			<< difference[i]->name
			<< setw(15) << difference[i]->code
			<< setw(20) << difference[i]->Dr
			<< setw(20) << difference[i]->semester;
		if (difference[i]->pre.size() == 0) cout << "No prerequisites." << endl;
		else {
			for (auto& x : difference[i]->pre) {
				cout << x->name << ", ";
			}
			cout << endl;
		}
	}

	cout << "\nChoose a course or press 'b' to go back: ";

	char choice;
	cin >> choice;

	if (choice == 'b' or choice == 'B') { cin.ignore(); studentMenu(s); }

	choice = choice - 49;
	cin.ignore();

	//=========================================================================================================================
	bool felog2 = true;
	for (auto& x : difference[choice]->pre) {
		bool felog = false;
		for (auto& y : s->courses) {
			if (x->name == y->name) { felog = true; break; }
		}
		if (!felog) { felog2 = false; break; }
	}

	if (felog2) {
		
		difference[choice]->studentCnt.insert((s));
		s->courses.emplace_back(difference[choice]);


		cout << "Added!";
		delay(2000);
		studentMenu(s);

	}
	else cout << "You do not have all the prerequisites for this course!" << endl;
	delay(2000);
	registerCourse(s);


	//=========================================================================================================================




}

void stViewCourse(shared_ptr<Course>& c, shared_ptr<Student>&S) {

	system("CLS");
	cout << "Course Info" << endl;
	L();

	c->stSummary();
	L();
	listAss(S, c);

	if (c->assignments.size() != 0) cout << "Select an assignment to view or ";
	cout << "press 'b' to go back: ";

	char stroke;
	stroke = _getch();

	if (stroke == 'b') coursesList(S);
	else {

		system("CLS");


		viewAss(c->assignments[static_cast <int> (stroke) - 49], S, c);

	}
}

void autoAdd(shared_ptr<Course>& C) {
	for (auto& x : STUDENTS) {
		if (x->semester == C->semester) {
			x->courses.emplace_back(C);
			C->studentCnt.insert(x);
		}
	}
}

void notAutoAdd(shared_ptr<Course>& C) {
	bool flag = false, flag3 = true;
	for (auto& x : STUDENTS) {
		if (x->semester != C->semester) continue;
		for (auto& y : C->pre) {
			bool flag2 = false;
			for (auto& z : x->courses) {
				if (y->name == z->name) { flag2 = true; break; }
			}
			if (!flag2) { flag3 = false; break; }
		}
		if (flag3) {
			x->courses.emplace_back(C);
			C->studentCnt.insert(x);
		}
	}
}
//df

void doctorMenu(shared_ptr<Doctor>& d) {


	system("CLS");
	cout << "Press a key corresponding to your choice: " << endl;
	L();
	cout << "1- Courses list" << endl
		<< "2- Create a course" << endl
		<< "3- Log out" << endl
		<< "Your choice: ";

	char stroke = _getch();
	switch (stroke) {
	case '1': coursesList(d);			break;
	case '2': create(d);				break;
	case '3': mainMenu();				break;
	}
}

void coursesList(shared_ptr<Doctor>& D) {

	system("CLS");

	char stroke;

	cout << "List of courses: " << endl;
	L();

	cout << left << setw(24) << "Course Name" << setw(18) << "Course Code"
		<< setw(22) << "Number of students" << "Number of assignments" << endl << endl;

	for (int i = 0; i < D->courses.size(); i++) {
		cout << i + 1 << "- " << left << setw(21) << D->courses.at(i)->name
			<< setw(18) << D->courses.at(i)->code << setw(25)
			<< D->courses.at(i)->studentCnt.size() << D->courses.at(i)->assignments.size() << endl;
	}

	L();
	cout << "Select the number of the course you want to view or press 'b' to go back: ";
	stroke = _getch();
	if (stroke == 'b' || stroke == 'B') doctorMenu(D);
	else	drViewCourse(D->courses[(stroke)-49], D);


}




void drViewCourse(shared_ptr<Course>& c, shared_ptr<Doctor>& D) {

	system("CLS");
	cout << c->name << " -> Course Info" << endl;
	L();

	c->drSummary();

	L();
	cout << "Press a key corresponding to your choice or b to go back: " << endl << endl
		<< "1- Assignments list \n"
		<< "2- Create a new assignment \n"
		<< "3- View Students grades for this course \n"
		<< endl << "Your choice: ";


	char stroke = _getch();

	if (stroke == 'D' or stroke == 'd') {
		//system("CLS");
		cout << endl;

		system("CLS");
		cout << "Please enter the course description for " << c->name << ": \n";
		L();
		c->setDesc();
		drViewCourse(c, D);

	}

	if (stroke == 'b') coursesList(D);
	if (stroke == '1') {
		listAss(D, c);
		drViewCourse(c, D);
	}
	if (stroke == '2') {
		system("CLS");
		addAssignmentToCourse(D, c);
		delay(1000);
		drViewCourse(c, D);
	}
	if (stroke == '3') {
		system("CLS");
		courseGrades(c);
		drViewCourse(c, D);

	}




}

void create(shared_ptr<Doctor>& d) {
	system("CLS");
	string n, c; int sem;
	int isPre = 0;
	cout << "Create a course" << endl;
	L();
	cout << "Enter details: " << endl << endl;

	cout << "Course name: "; getline(cin, n);
	cout << "Course code: "; getline(cin, c);
	cout << "Default semester: "; cin >> sem; cin.ignore();
	int stat;

	cout << "\nPrerequisites?: \n"
		<< left << setw(35) << "1-No prerequisites"
		<< "2-Add prerequisites\n"
		<< "choice: "; cin >> stat; cin.ignore();

	COURSES.emplace_back(make_shared<Course> (Course(n, c, d->name, sem)));

	if (stat == 1) {

		addToDr(d);
		autoAdd(COURSES.back());
	}

	else if (stat == 2) {
		edit_pre(COURSES.back());
		addToDr(d);
		notAutoAdd(COURSES.back());
	}

	L();
	cout << "Course created successfully!" << endl;
	delay(2000);
	coursesList(d);

}

void addAssignmentToCourse(shared_ptr<Doctor>& d, shared_ptr<Course>& c) {

	string nama;  double fM; string dL;  deque <string> ds;
	cout << "Enter the details for the assignment: " << endl << endl;

	cout << "Assignment name: ";
	getline(cin, nama);
	cout << "Assignment description: \n";
	string temp;
	while (getline(cin, temp) and temp != "") {
		ds.push_back(temp);
	}
	cout << "Assignment full mark: "; cin >> fM; cin.ignore();
	cout << "Assignment dead line: "; getline(cin, dL);
	shared_ptr <Assignment> asi = make_shared <Assignment>(Assignment(nama, fM, dL, c, d, ds));
	c->assignments.emplace_back(asi);

	cout << "Assignment added!" << endl;


}

void listAss(shared_ptr<Student>&s, shared_ptr<Course>& c) {

	cout << "List of Assignments" << endl;
	L();
	if (c->assignments.size() == 0) cout << "This course has no assignments!" << endl;
	else {
		cout << left << setw(30)
			<< "Assignment name"
			<< setw(25)
			<< "Assignment Deadline"

			<< setw(25)
			<< "Assignment fullMark"
			<< "My submissions"

			<< endl << endl;

		int j = 0;
		for (auto& x : c->assignments) {
			cout << left << ++j << "- "
				<< setw(27) << x->name
				<< setw(25) << x->deadLine
				<< setw(25) << x->fullMark;
			//if (s.submitted.size() == 0) { cout << "No Submissions" << endl; continue; }
			auto fo = find(s->submitted.begin(), s->submitted.end(), x);
			if (fo != s->submitted.end()) cout << "Submitted"; else cout << "No Submissions";
			cout << endl;
		}

		L();
	}

}

void listAss(shared_ptr<Doctor>& d, shared_ptr<Course>& c) {
	system("CLS");
	cout << "List of Assignments" << endl;
	L();
	if (c->assignments.size() == 0) { cout << "This course has no assignments!" << endl; delay(2000); return; }
	else {
		cout << left << setw(30)
			<< "Assignment name"
			<< setw(25)
			<< "Assignment Deadline"

			<< setw(25)
			<< "Assignment fullMark"
			<< "Number of submissions"

			<< endl << endl;

		int j = 0;
		for (auto& x : c->assignments) {
			cout << left << ++j << "- "
				<< setw(27) << x->name
				<< setw(25) << x->deadLine

				<< setw(25) << x->fullMark
				<< x->subs.size() << endl;
		}
	}

	L();

	cout << "Select an assignment to view or press 'b' to go back: ";
	char stroke = _getch();
	if (stroke == 'b') return;
	system("CLS");
	viewAss(c->assignments[(int)stroke - 49], d);


	listAss(d, c);


}
void bye() {
	cout << "A";
}

void addToDr(shared_ptr<Doctor>& d) {

	d->courses.emplace_back(COURSES.back());

}
void edit_pre(shared_ptr<Course>& cc) {

	system("CLS");
	cout << "Add prerequisites for " << cc->name << endl;
	L();

	cout << "List of courses you can add as pre requisites: " << endl;
	L();

	bool flag = true;

	int cnt = 0;
	map <int, shared_ptr<Course> > m;

	cout << left
		<< setw(35)
		<< "Course Name"
		<< setw(15) << "Course Code"
		<< setw(20) << "Default Semester"
		<< "Prerequisites";
	cout << endl << endl;




	for (auto& x : COURSES) {
		bool flag = true;
		if (x->name == cc->name) continue;
		if (x->semester > cc->semester) continue;
		for (auto& y : cc->pre) { if (y->name == x->name) flag = false; }
		for (auto& z : x->pre) { if (cc->name == z->name) flag = false; }
		if (!flag) continue;
		cout << left << ++cnt << "- "
			<< setw(32) << x->name
			<< setw(15) << x->code
			<< setw(20) << x->semester;
		if (x->pre.size() == 0) cout << "No prerequisites." << endl;
		else {
			for (auto& g : x->pre) {
				cout << g->name << ", ";
			}
			cout << endl;
		}

		m.emplace(cnt, x);
	}
	static int onlyOnce = 0;				// to take the initial size of the number of prerequisites allowed

	if (!onlyOnce) soz = (int)m.size();

	onlyOnce++;
	L();
	cout << "Choose a course to add or press b to go back: ";
	char choice;
	cin >> choice;
	cin.ignore();
	if (choice == 'b' or choice == 'B') return;
	else cc->pre.emplace_back(m[choice - 48]);
	L();
	cout << "Prerequisite added successfully" << endl; delay(1500);

	system("CLS");

	cout << "list of prerequisites for " << cc->name << endl;
	L();

	int cnt2 = 0;
	for (auto& x : cc->pre) {
		cout << ++cnt2 << "- " << x->name << endl;
	}
	L();
	cout << "Press c to add another prerequisite or press b to go back: ";

	cin >> choice;

	cin.ignore();

	if (choice == 'b' or choice == 'B') return;
	else if (choice == 'c' or choice == 'C') {

		if (cc->pre.size() == soz) { L(); cout << "No more courses to add\n"; delay(1600); return; }

		edit_pre(cc);
	}

}
void viewSub(shared_ptr <pair<shared_ptr <Student> const, shared_ptr<Submission> > > temp, shared_ptr<Assignment>& as, shared_ptr<Doctor>& d) {
	system("CLS");
	cout << "View submission" << endl;
	L();
	cout << "Submission name: " << temp->second->name << endl
		<< "Student name: " << temp->first->name << endl
		<< "Student answer: " << endl;
	for (auto& x : temp->second->ans) {
		cout << x << endl;
	}
	cout << endl;
	cout << "Submission status: " << temp->second->graded << endl;
	cout << "Marks: ";
	(temp->second->graded == "Not graded") ? cout << "N/A" << endl : cout << temp->second->mark << endl;

	L();

	cout << "Comments:" << endl;
	L();
	viewComments(temp->second);

	cout << "Press b to go back, c to add a coment, or g to grade assignment";
	char stroke = _getch();
	if (stroke == 'b' or stroke == 'B') viewAss(as, d);
	else if (stroke == 'g' or stroke == 'G') {
		cout << endl;
		L();
		cout << "Enter the grade: ";
		double mark;
		cin >> mark;
		temp->second->graded = "Graded";
		temp->second->mark = mark;
		cin.ignore();
		cout << "Marks for the submission has been updated" << endl;
		delay(1500);
		viewSub(temp, as, d);
	}
	else if (stroke == 'c' or stroke == 'C') {
		cout << "\nnew comment: ";
		string tomp = "Dr." + d->name + ": \n";
		deque <string> t;
		t.emplace_back(tomp);

		while (getline(cin, tomp) and tomp != "") {
			t.emplace_back(tomp);
		}
		if (t.size() > 1) {
			temp->second->addComment(t);
			cout << "Comment added" << endl;
		}

		else cout << "No comment added" << endl;
		delay(1500);
		viewSub(temp, as, d);
	}
}

void subList(shared_ptr<Assignment>& as, shared_ptr<Doctor>& d) {
	cout << "List of submissions" << endl;
	L();
	if (as->subs.size() == 0) {
		cout << "No submissions so far!\nPress 'b' to go back" << endl;
		char stroke = _getch();
		if (stroke == 'b' or stroke == 'B') return;
	}
	cout << left
		<< setw(30) << "Submission name"
		<< setw(30) << "Student name"
		<< setw(20) << "Status"
		<< "Mark" << endl << endl;
	int j = 0;


	deque < shared_ptr <pair<shared_ptr <Student> const, shared_ptr<Submission> > > > temp;

	for (auto& x : as->subs) {
		cout << left << ++j << "- "
			<< setw(27) << x.second->name
			<< setw(30) << x.first->name
			<< setw(20) << x.second->graded;
		(x.second->graded == "Not graded") ? cout << "N/A" : cout << x.second->mark;
		cout << endl;
		temp.emplace_back(make_shared < pair < shared_ptr <Student> const, shared_ptr<Submission > > >(x));

	}
	cout << endl;
	cout << "Choose a submission to view or press 'b' to go back: ";
	char stroke = _getch();
	if (stroke == 'b') return;
	else viewSub(temp[(int)stroke - 49], as, d);

}
void viewAss(shared_ptr<Assignment>& as, shared_ptr<Doctor>& d) {
	system("CLS");
	cout << "View Assignment" << endl;
	L();
	cout << "Assignment name: " << as->name << endl;
	cout << "Assignment Description: \n";
	for (auto& x : as->desc) {
		cout << x << endl;
	}
	cout << endl;
	cout << "Assignment deadline: " << as->deadLine << endl;
	cout << "Assignment full mark: " << as->fullMark << endl;
	cout << endl;

	subList(as, d);

}
void makeSubmission(shared_ptr<Student>&s, shared_ptr<Assignment>& as) {

	string n;   deque <string > ans;

	cout << "Submission name: "; getline(cin, n);
	cout << "Your answer: " << endl;
	string temp = "-";
	while (getline(cin, temp) and temp != "") {
		ans.push_back(temp);
	}
	s->submitted.emplace_back(as);
	
	as->subs.emplace(s, make_shared<Submission>(Submission(n, as, ans)));

}

void viewAss(shared_ptr<Assignment>& as, shared_ptr <Student>& s, shared_ptr<Course>& c) {

	cout << "Assignment name: " << as->name << endl;
	cout << "Assignment Description: \n";
	for (auto& x : as->desc) {
		cout << x << endl;
	}
	cout << endl;
	cout << "Assignment deadline: " << as->deadLine << endl;
	cout << "Assignment full mark: " << as->fullMark << endl;
	//cout << "Assignment Average: " << /*AVg*/ endl;
	cout << endl;
	L();
	cout << "Your Submission: " << endl << endl;



	auto it = find(s->submitted.begin(), s->submitted.end(), as);
	if (it == s->submitted.end()) {

		cout << "No submission made, Press 's' to make a submission or press 'b' to go back" << endl;
		char stroke;
		stroke = _getch();

		if (stroke == 'b') stViewCourse(c, s);
		else if (stroke == 's' or stroke == 'S') {
			system("CLS");

			makeSubmission(s, as);
			L();
			cout << "Thanks for making a submission!";
			delay(1000);
			cout << endl;
			stViewCourse(c, s);
		}

	}
	else {

		cout << left
			<< setw(30) << "Submission name"
			<< setw(25) << "Submition status"
			<< "Marks" << endl
			<< setw(30) << as->subs[s]->name
			<< setw(25) << as->subs[s]->graded;
		(as->subs[s]->graded == "Not graded") ? cout << "N/A" : cout << as->subs[s]->mark;
		cout << endl;
		L();

		cout << "Press s to view submission or b to go back: ";
		char stroke;
		stroke = _getch();

		if (stroke == 'b') stViewCourse(c, s);
		else viewSub(as->subs[s], s, c);

	}


}

void viewComments(shared_ptr <Submission>& sub) {
	int cnt = 1;
	for (auto& x : sub->comments) {

		for (auto& y : x) {
			for (int i = 0; i < cnt; i++) cout << '\t';
			cout << y << endl;
		}
		L();
		cnt++;
	}

}
void viewSub(shared_ptr <Submission>& sub, shared_ptr<Student>&s, shared_ptr<Course>& c) {
	system("CLS");
	cout << "Submission for " << sub->asi->name;
	L();
	cout << "Submission name: " << sub->name << endl
		<< "Answer: " << endl;
	for (auto& x : sub->ans) {
		cout << x << endl;
	}
	cout << endl << "Grade: ";
	if (sub->graded == "Not graded") cout << "N/A" << endl;
	else cout << sub->mark << endl;
	L();
	cout << "Comments: " << endl;
	L();
	viewComments(sub);
	cout << endl;
	L();
	cout << "Press 'b' to go back, or press 'c' to post a comment";
	char stroke = _getch();
	if (stroke == 'b' or stroke == 'B') stViewCourse(c, s);
	else if (stroke == 'c' or stroke == 'C') {
		cout << "\nnew comment: ";
		string temp = s->name + ": \n";
		deque <string> t;
		t.emplace_back(temp);

		while (getline(cin, temp) and temp != "") {
			t.emplace_back(temp);
		}
		if (t.size() > 1) {
			sub->addComment(t);
			cout << "Comment added" << endl;

		}


		else cout << "No comment added" << endl;
		delay(1500);
		viewSub(sub, s, c);
	}
}

void courseGrades(shared_ptr<Course>& c) {

	if (c->assignments.size() == 0) {
		cout << "This course does not have any assignments yet";
		delay(2000);
		return;
	}

	if (c->studentCnt.size() == 0) {
		cout << "No students are enrolled in this course";
		delay(2000);
		return;

	}
	cout << left << setw(25) << "Student";
	for (auto& x : c->assignments) {
		cout << setw(25) << x->name;
	}
	cout << endl;
	L();


	for (auto& x : c->studentCnt) {

		cout << setw(25) << x->name;

		for (auto& y : c->assignments) {
			if (y->subs.find(x) == y->subs.end()) {
				cout << left << setw(22) << "Not Submitted";
				continue;
			}
			if (y->subs[x]->graded == "Not graded") cout << left << setw(23) << "Not Graded";
			else cout << y->subs[x]->mark << "/" << setw(23) << y->fullMark;
		}
	
		cout << endl;
	}
	cout << endl;
	L();
	cout << "press b to go back";
	char stroke = _getch();
	if (stroke == 'b' or stroke == 'B') return;

}

void gradeList(shared_ptr<Student>&s) {
	system("CLS");
	cout << "Grade List" << endl;
	L();
	double mark;

	cout << setw(40) << "Course" << "Marks" << endl; L();

	for (auto& x : s->courses) {
		mark = 0;
		cout << left << setw(40) << x->name;
		for (auto& y : x->assignments) {
			if (y->subs.find(s) == y->subs.end()) continue;
			if (y->subs[s]->graded == "Not graded") continue;
			mark += y->subs[s]->mark;
			
		}
		
		cout << mark << "%";
		cout << endl;
	}

	L();

	cout << "Press b to go back: ";
	char stroke = _getch();
	if (stroke == 'b' or 'B') return;

}


void loadC(shared_ptr<Student>&x) {
	for (int i = 0; i < COURSES.size(); i++) {
		if (COURSES[i]->semester == x->semester) {

			x->courses.emplace_back(COURSES[i]);
			
			COURSES[i]->studentCnt.insert(x);

		}
	}
}