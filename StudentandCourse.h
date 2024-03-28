//Studnet Header file

#include <iostream>//input & output stream header file
using namespace std;

class Student
{
private:
	//private members: can only be referenced within the definitions of member functions
	int id; //member variable hold student ID
	string name;//member variable hold student name
	int score;//member variable hold student score

public:
	//constructors declaration
	Student(); // deafult constructor
	Student(int x, string y, int z);//constructor with 3 parameter
	//member functions
	//because of the private part we need setter and getter

	//setter functions
	void setID(int x);
	void setName(string y);
	void setScore(int z);

	//getter functions
	int getID()const;
	string getName()const;
	int getScore()const;
};

struct Course
{
	//member varables
	string title;// course name
	int number_of_students;// Number of student in the course
	Student* list;// save the student's ID, names, and score in here
};

// Function declarations
void AskFile(string& file);
void OpenFile(string filename, Course& course);//using call by reference
void Menu(int& select, string file1, string file2, string file3);//using call by reference
void MenuOne(Course* course);//using pointers
bool MenuTwoLoopCourses( Student* Course1, Course* Course2, Course* Course3, int& indexj, int& indexk); //put the loops in a function
void MenuTwo(Course* ACourse, Course* BCourse, Course* CCourse);//using pointers
bool MenuThreeLoopCourses( Student* Course1, Course* Course2, Course* Course3, int& indexj, int& indexk);//put the loops in a function
void MenuThree(Course* ACourse, Course* BCourse, Course* CCourse);//using pointers
void MenuFour(Course* course);//using pointers
