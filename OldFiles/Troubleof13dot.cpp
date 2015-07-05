#include<iostream>
#include<string>
#include<fstream>
using namespace std;
const int size = 1000;
int save[size];
string save2[100];
int save1[size];
//structure of student
struct student {
	int id;
	string name;
	int sec;
	int academ_year;
	string grade;
} x;
//structure of years
struct years {
	int id;
	string yearname;
	int numofstudents;
	student x[size]; //array of students
} y;
void addstudent(years & y, student x) {
	cout << "Enter number of students:" << endl;
	cin >> y.numofstudents;
	for (int i = 1; i <= y.numofstudents; i++) {
		cout << "Enter the student's " << i << " data " << endl;
		cout << "ID:";
		cin >> y.x[i].id;
		if ((y.x[i].id == 0) || (y.x[i].id < 0)) {
			cout << "can not enter this id " << endl;
			break;
		}
		cout << "Name:";
		cin.ignore();
		getline(cin, y.x[i].name);
		cout << "Section Number: ";
		cin >> y.x[i].sec;
		if ((y.x[i].sec == 0) || (y.x[i].sec > 20) || (y.x[i].sec < 0)) {
			cout << "can not enter this section" << endl;
			break;
		}
		cout << "Academic Year:";
		cin >> y.x[i].academ_year;
		if ((y.x[i].academ_year == 0) || (y.x[i].academ_year < 0)
				|| (y.x[i].academ_year > 4)) {
			cout << "can not enter this academic year" << endl;
			break;
		}
		cout << "Total Grade: " << endl
				<< "(excellent or verygood or good or fair or fail)" << endl;
		cin >> y.x[i].grade;
		save[i] = y.x[i].academ_year; //array to save the academic year and return it in display function
		save2[i] = y.x[i].grade; //array to save the grades and return it in precentage function
		save1[i] = y.x[i].sec;
	}
}
void modifystudent(years& y, student & x) {
	int id;
	cout << "to display student by section" << endl;
	cout << "Enter id:"; //search student by section
	cin >> id;
	for (int i = 0; i < size; i++) {
		if (id == y.x[i].id) {
			cout << "Enter only the new data you want to modify:" << endl;
			cout << "Enter the new Name:";
			cin.ignore();
			getline(cin, y.x[i].name);
			cout << "Enter the new ID:";
			cin >> y.x[i].id;
			if ((y.x[i].id == 0) || (y.x[i].id < 0)) {
				cout << "can not enter this id " << endl;
				break;
			}
			cout << "Enter the new section:";
			cin >> y.x[i].sec;
			if ((y.x[i].sec == 0) || (y.x[i].sec > 20) || (y.x[i].sec < 0)) {
				cout << "can not enter this section" << endl;
				break;
			}
		}
	}
	//	for (int i = 0; i < y.numofstudents; i++)
	//	{
	//	if (id != y.x[i].id)
	//		cout << "id is not founded" << endl;
	//	break;
	//}
}
void displaystudent(years& y, student & x, int z, int yr) //display student by certain section
		{
	for (int i = 0; i < size; i++) {
		if ((z == y.x[i].sec) && (yr == y.x[i].academ_year)) {
			cout << "Student's Name: ";
			cout << y.x[i].name << endl;
			cout << "Student's ID: ";
			cout << y.x[i].id << endl;
		}
	}
}
void Display_Data(years& y, student & x) // Display Data by Academic Year
		{
	cout << "Enter the Academic Year: " << endl;
	int Academic_Year;
	cin >> Academic_Year;
	for (int i = 1; i <= size; i++) {
		if (Academic_Year == save[i]) {
			cout << "Student's Name: ";
			cout << y.x[i].name << endl;
			cout << "Student's ID: ";
			cout << y.x[i].id << endl;
			cout << "Student's Section: ";
			cout << y.x[i].sec << endl;
		}
	}
}
void year(student & x, years & y, int z) //calculate precantage function in each certain academic year
		{
	float o, l, k, j, h;
	int a, counter = 0, counter1 = 0, counter2 = 0, counter3 = 0, counter4 = 0,
			counter5 = 0;
	for (int i = 1; i <= size; i++) {
		if (save[i] == z) // "z" is the no. of year entered by user
				{
			counter++;
			a = counter;
			if (save2[i] == "excellent") {
				counter1++;
			} else if (save2[i] == "verygood") {
				counter2++;
			} else if (save2[i] == "good") {
				counter3++;
			} else if (save2[i] == "fair") {
				counter4++;
			} else if (save2[i] == "fail") {
				counter4++;
			}
		}
	}
	o = ((float) counter1 / (float) a) * 100;
	l = ((float) counter2 / (float) a) * 100;
	k = ((float) counter3 / (float) a) * 100;
	j = ((float) counter4 / (float) a) * 100;
	h = ((float) counter5 / (float) a) * 100;
	for (int i = 1; i <= y.numofstudents; i++) {
		if (o != 0) {
			cout << "Excellent:" << o << "%" << endl;
			break;
		}
	}
	for (int i = 1; i <= y.numofstudents; i++) {
		if (l != 0) {
			cout << "Very Good:" << l << "%" << endl;
			break;
		}
	}
	for (int i = 1; i <= y.numofstudents; i++) {
		if (k != 0) {
			cout << "Good:" << k << "%" << endl;
			break;
		}
	}
	for (int i = 1; i <= y.numofstudents; i++) {
		if (j != 0) {
			cout << "Fair:" << j << "%" << endl;
			break;
		}
	}
	for (int i = 1; i <= y.numofstudents; i++) {
		if (h != 0) {
			cout << "Fail:" << h << "%" << endl;
			break;
		}
	}
}
void cases() //function of menue used in switch
{
	cout << "Please enter  " << endl;
	cout << "              1 if you want to add a new student" << endl;
	cout << "              2 if you want to modify the data of a student"
			<< endl;
	cout
			<< "              3 if you want to display students in a certain section number"
			<< endl;
	cout
			<< "              4 if you want to display students in a certain academic year"
			<< endl;
	cout
			<< "              5 display the percentage of each grade in a certain academic year"
			<< endl;
	cout << "              6 if you want to exit" << endl;
}
int main2() {
	student s;
	years q;
	int z, yr;
	cout << "                         Welcome To Students' System" << endl;
	cout << "The academic years are 4: " << endl;
	ifstream infile;
	infile.open("years.txt");
	string x, y, v, w;
	infile >> x >> y >> v >> w;
	cout << x << endl << y << endl << v << endl << w << endl << endl << endl;
	int r;
	cases();
	cin >> r;
	while (r != 6) {
		switch (r) {
		case 1:
			addstudent(q, s);
			cout << "	          ** You have successfully added "
					<< q.numofstudents << " students **" << endl;
			cases();
			cin >> r;
			break;
		case 2:
			modifystudent(q, s);
			cout
					<< "         ** You have successfully Modify the Student information **"
					<< endl;
			cases();
			cin >> r;
			break;
		case 3:
			cout << "Enter year no.";
			cin >> yr;
			cout << "Enter section no.";
			cin >> z;
			displaystudent(q, s, z, yr);
			cout
					<< "         ** You have successfully Display the studdent in certain section **"
					<< endl;
			cases();
			cin >> r;
			break;
		case 4:
			Display_Data(q, s);
			cout
					<< "         ** You have successfully Display the studdent in certain Academic year **"
					<< endl;
			cases();
			cin >> r;
			break;
		case 5: {
			cout << "enter a year to display precentage" << endl;
			cin >> z;
			year(s, q, z);
			cout
					<< "         ** You have successfully calculated & viewed the percentages **"
					<< endl;
			cases();
			cin >> r;
		}
			break;
		default:
			break;
		}
	}
	return 0;
}
