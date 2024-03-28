#include "StudentandCourse.h"

#include <fstream>//file stream header file
#include <iomanip>//input & output manipulation header file
//Constructor definition
//Implementation of Constructors
Student::Student() : id(0), name(" "), score(0){}
Student::Student(int x, string y, int z):id(x), name(y), score(z) {}

//Implementing Setter Functions
void Student::setID(int x){id = x;}
void Student::setName(string y){name = y;}
void Student::setScore(int z){score = z;}

//Implementing Getter Functions
int Student::getID()const{return id;}
string Student::getName()const{return name;}
int Student::getScore()const{return score;}

void AskFile(string& file)//ask for files
{
	static int countfile = 1;
    cout << "Enter filename #"<<countfile<<" : ";
    cin >> file; 
    countfile++;
}

void OpenFile(string filename, Course& course)
{
	ifstream infile;
	infile.open(filename); //Open file
	if(infile.fail()) //Check if opening file failed
	{
		//Exit program if file failed to open
		cout << "Input file opening failed. "<<endl;
		exit(1);
	}

	// Set local varables
	int id, score; // id is for saving Student's ID number and score is for saving Student's score to the data
	string name;// name is for saving Student's name
	int index = 0; //Set count
	infile>>course.title>>course.number_of_students;//Read course data
	course.list = new Student [course.number_of_students];//Set dynamic array 
	while(!infile.eof())//Loop until the end of file
	{
		infile>>id>>name>>score;//Read
		//Storing student's ID, name, and socre to the dynamic array
		course.list[index].setID(id);
		course.list[index].setName(name);
		course.list[index].setScore(score);
		index++;
	}
	infile.close(); //Close file after reading

	//Selection Sorting where smaller ID number goes on top and larger goes to the bottom
	for(int i = 0; i < course.number_of_students-1; i++)
	{
		for(int j = i+1; j < course.number_of_students; j++)
		{
			if(course.list[i].getID()>course.list[j].getID())
			{
				Student temp = course.list[i];
				course.list[i] = course.list[j];
				course.list[j] = temp;
			}
		}
	}
}

void Menu(int& select, string file1, string file2, string file3)//Display Menu for user and send user's selection to the main
{
	static int count = 0; //set a count to prevent printing twice in the first time
	if(count > 0)
	{
		cout << "Enter filename #1 : "<< file1<<endl;
		cout << "Enter filename #2 : "<< file2<<endl;
		cout << "Enter filename #3 : "<< file3<<endl;
		cout << endl;
	}
	cout << "================Menu================\n"<<"1. Show all course lists(sorting)\n";
	cout << "2. List of students who take all courses\n"<<"3. List of students who take two courses\n";
	cout << "4. Print out top three scores for each course\n"<<"5. Exit\n";
	cout <<"-----> Select : ";
	cin >> select;
	cout << endl;
	count++;
}

void MenuOne(Course* course)//Display all course details
{
	cout << "==============="<<course->title<<"===============\n\n";
	//Print all students' ID, Name and Score for the courses
	for(int i = 0; i < course->number_of_students; i++)
	{
		cout <<setw(10)<< course->list[i].getID()<<setw(13)<<course->list[i].getName()<<setw(5)<<course->list[i].getScore()<<endl;
	}
	cout << endl;
}

bool MenuTwoLoopCourses( Student* Course1, Course* Course2, Course* Course3, int& indexj, int& indexk)
{
	//Find the number of students who are taking three courses
	for(indexj = 0; indexj < Course2->number_of_students; indexj++)
	{
		if(Course1->getID() == Course2->list[indexj].getID())//Check if student is taking tow courses
		{
			for(indexk = 0; indexk < Course3->number_of_students; indexk++)
			{
				if(Course1->getID() == Course3->list[indexk].getID())//Check if student is taking three courses
				{
					return true;
				}
			}
		}
	}
	return false;
}

void MenuTwo(Course* ACourse, Course* BCourse, Course* CCourse )//Display students who are taking all three courses
{
	//Local varaible
	int count = 0; //set count for the students who are taking three courses to zero
	int j = 0, k = 0;

	//Find the number of students who are taking three courses
	for(int i = 0; i < ACourse->number_of_students; i++)
	{
		if(MenuTwoLoopCourses(&ACourse->list[i], BCourse, CCourse, j, k))
		{
			count++;
		}
	}

	//Print the number of students taking three courses
	cout <<setw(35)<< "There are "<< count<<" students who take 3 courses"<<endl;
	cout<<"----------------------------------------------------------------------------------------";
	cout << endl;

	//Printing out the students who are taking three courses
	for(int i = 0; i < ACourse->number_of_students; i++)
	{
		if(MenuTwoLoopCourses(&ACourse->list[i], BCourse, CCourse, j, k))
		{
			cout <<setw(10)<< ACourse->list[i].getID()<<setw(13)<<ACourse->list[i].getName();
			cout << setw(15)<<ACourse->title<<" ("<<ACourse->list[i].getScore()<<")";
			cout<<setw(15)<<BCourse->title<<" ("<<BCourse->list[j].getScore()<<")";
			cout << setw(15)<<CCourse->title<<" ("<<CCourse->list[k].getScore()<<")";
			cout << endl;
		}
	}
	cout << endl;
}

bool MenuThreeLoopCourses( Student* Course1, Course* Course2, Course* Course3, int& indexj, int& indexk)
{
	bool twoonly; //see if a student is taking only two courses
	for(indexj = 0; indexj < Course2->number_of_students; indexj++)
	{
		twoonly = true; //set student is taking only two courses
		if(Course1->getID() == Course2->list[indexj].getID())
		{
			for(indexk = 0; indexk < Course3->number_of_students; indexk++)
			{
				if(Course1->getID() == Course3->list[indexk].getID())//check if the student is taking three courses
				{
					twoonly = false; // if student is taking three courses, then student is not taking ONLY two courses
					break;
				}
			}
			if(twoonly)//if student found to be taking only two classes, count +1
			{
				return true;
			}
		}
	}
	return false;
}

void MenuThree(Course* ACourse, Course* BCourse, Course* CCourse)
{
	int count = 0; //keep track of the number of students
	int j =0, k = 0;
	//Find the number of students who are taking two courses
	for(int i = 0; i < ACourse->number_of_students; i++)
	{
		if(MenuThreeLoopCourses(&ACourse->list[i], BCourse, CCourse, j , k))
		{
			count++;
		}
	}

	//Print the number of students only taking two classes
	cout <<setw(20)<< "There are "<< count<<" students who take "<<ACourse->title<<" and "<<BCourse->title;
	cout<<endl<<"------------------------------------------------------------------------\n";
	for(int i = 0; i < ACourse->number_of_students; i++)
	{
		if(MenuThreeLoopCourses(&ACourse->list[i], BCourse, CCourse, j, k))
		{
		cout <<setw(10)<<ACourse->list[i].getID()<<setw(13)<<ACourse->list[i].getName();
		cout <<setw(15)<<ACourse->title<<" ("<<ACourse->list[i].getScore()<<")";
		cout <<setw(15)<<BCourse->title<<" ("<<BCourse->list[j].getScore()<<")";
		cout <<endl;
		}
	}
	cout << endl;
}

void MenuFour(Course* course)//Display top three student of each course
{
	//Local varaibles
	bool scorePrint =true; // set to print the highest score one time
	int firstmax =0; // set to hold the highest score 
	int secondmax = 0; // set to hold the second highest score
	int thirdmax = 0; //set to hold the third highest score
	int count = 1; //set to print the ranking(1st place, 2nd place, 3rd place)
	cout << "[ "<<course->title<<" Top Three Scores ]"<<endl;

	//Find the number of students who are having the highest score
	for(int i = 0; i < course->number_of_students; i++)
	{
		if(course->list[i].getScore()>=firstmax)
		{
			//Set the first highest score to firstmax
			firstmax = course->list[i].getScore(); 
		}
	}
	cout << count<<".";

	//Print all students' ID and name in first place with the first score
	for(int i = 0; i < course->number_of_students; i++)
	{
		if(course->list[i].getScore() == firstmax)//if students' score is equal to the first highest score
		{
			if(scorePrint)//print the highest score one time
			{
				cout << setw(3)<<course->list[i].getScore();
				scorePrint = false;
			}
			// Print students's ID and name with the first highest score
			cout<< endl << setw(10)<<course->list[i].getID()<<setw(13)<<course->list[i].getName();
		}
	}
	count++; //go to second place
	cout << endl;

	////Find the number of students who are having the second highest score
	scorePrint = true; //set it to true again to print the second highest score
	for(int i = 0; i < course->number_of_students; i++)
	{
		int score2 = course->list[i].getScore(); // store the score for ith student in order to check in the next step
		if(score2>=secondmax&& score2<firstmax)
		{
			//Set the second highest score to secondmax
			secondmax = course->list[i].getScore();
		}
	}
	cout << count<<".";

	//Print all students' ID and name in second place with the second score
	for(int i = 0; i < course->number_of_students; i++)
	{
		if(course->list[i].getScore() == secondmax)
		{
			if(scorePrint)//print the second highest score one time
			{
				cout << setw(3)<<course->list[i].getScore();
				scorePrint = false;
			}
			// Print students's ID and name with the second highest score
			cout<< endl << setw(10)<<course->list[i].getID()<<setw(13)<<course->list[i].getName();
		}
	}
	count++;//go to third place
	cout << endl;

	//Find the number of students who are having the third highest score
	scorePrint = true;
	for(int i = 0; i < course->number_of_students; i++)
	{
		int score3 = course->list[i].getScore();// store the score for ith student in order to check in the next step
		if(score3>=thirdmax&& score3<secondmax)
		{
			//Set the third highest score to thirdmax
			thirdmax = course->list[i].getScore();
		}
	}
	cout << count<<".";

	////Print all students' ID and names in third place according to the three score
	for(int i = 0; i < course->number_of_students; i++)
	{
		if(course->list[i].getScore() == thirdmax)
		{
			if(scorePrint)//print the third highest score one time
			{
				cout << setw(3)<<course->list[i].getScore();
				scorePrint = false;
			}
			// Print students's ID and name with the third highest score
			cout<< endl << setw(10)<<course->list[i].getID()<<setw(13)<<course->list[i].getName();
		}
	}
	cout << endl<<endl;
}
