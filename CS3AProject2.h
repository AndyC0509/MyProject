#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
const int MAXPERSON = 2;
const int MAXBOOK = 3;

//Class Parents: Book
//Class Child: ChildrenBook, ComputerBook, Novel
class Book
{
    public:
    Book(){}
    Book (int code, string title, int available, int rented)
    {
        this -> code = code;
        this -> title = title;
        this -> available = available;
        this-> rented =rented;
    }

    void set_bookCode(int code){this->code = code;}
    void setTitle(string title){this->title = title;}
    void setAva(int available){this->available = available;}
    void setRented(int rented){this->rented = rented;}

    //Book paramter
    int get_bookCode() const {return code;}
    string getTitle() const {return title;}
    int getAva() const {return available;}
    int getRented() const {return rented;}

    //ChildrenBook paramter
    virtual void setAge(int){};
    virtual int getAge() const {return 0;}

    //ComputerBook paramter
    virtual void setPublisher(int){};
    virtual string getPublisher() const{return " ";};

    //Novel paramter
    virtual void setPublishDate(int)=0;
    virtual int getPublishDate() const=0;

    private:
    int code;
    string title;
    int available;
    int rented;
};

class ChildrenBook : public Book
{
    public:
    ChildrenBook() {}
    ChildrenBook (int code, string title, int availble, int rented, int age) : 
    Book(code, title, availble, rented) {
       this-> age = age;}

    //ChildrenBook paramter
    void setAge(int age){this->age = age;}
    int getAge() const {return age;}

    // ComputerBook paramter
    void setPublisher(int){};
    string getPublisher() const{return " ";};

    // Novel paramter
    virtual void setPublishDate(int){};
    virtual int getPublishDate() const {return 0;}

    private:
    int age;
};

class ComputerBook : public Book
{
    public:
    ComputerBook() {}
    ComputerBook (int code, string title, int availble, int rented, string publisher) :  
    Book(code, title, availble, rented){this -> publisher = publisher;}

    //ComputerBook paramter
    void setPublisher(int publisher){this->publisher = publisher;}
    string getPublisher() const {return publisher;}

    //Novel paramter
    virtual void setPublishDate(int){};
    virtual int getPublishDate() const {return 0;}

    private:
    string publisher;
};

class Novel : public Book
{
    public:
    Novel() {}
    Novel (int code, string title, int availble, int rented, int publish_date) :  
    Book(code, title, availble, rented){this->publish_date = publish_date;}

    void setPublishDate(int publish_date){this-> publish_date = publish_date;}
    int getPublishDate() const {return publish_date;}

    private:
    int publish_date;
};

struct bookNode
{
    Book* data;
    bookNode* link;
};
typedef bookNode* Bookptr;

//Class Parents: Person, 
//Class Child: Student, Teacher
class Person
{
    public:
    Person(){}
    Person (int id, string name, int count) : id(id), name(name), count(count){}

    void setID(int id){this-> id = id;}
    int getID() const {return id;}
    void setName(string name){this-> name = name;}
    string getName() const {return name;}
    void setcount(int count){this-> count = count;}
    int getcount() const {return count;}

    virtual void setcode(int,int)=0;
    virtual void returnBook(int)=0;
    virtual int getcode(int) const=0;

    private:
    int id;
    string name;
    int count;

};

class Student : public Person
{
    public:
    Student(){}
    Student (int id, string name, int count, int book1, int book2) : 
    Person(id, name, count) {code[0] = book1; code[1] = book2;}

    void setcode(int bookcode, int index)
    {
        code[index] = bookcode;
    }
    void returnBook(int index)
    {
        for (int i = index; i < getcount() - 1; i++) 
        {
            code[i] = code[i + 1];
        }
        code[getcount() - 1] = 0;
        
    }
    int getcode(int index) const 
    {
        return code[index];
    }
    
    private:
    int code[2];
};

class Teacher : public Person
{
    public:
    Teacher(){}
    Teacher(int id, string name, int count, int book1, int book2, int book3) : 
    Person(id, name, count) {code[0] = book1; code[1] = book2; code[2] = book3;}

    void setcode(int bookcode, int index)
    {
        code[index] = bookcode;
    }
    void returnBook(int index)
    {
        for (int i = index; i < getcount() - 1; i++) 
        {
            code[i] = code[i + 1];
        }
        code[getcount() - 1] = 0;
    }

    int getcode(int index) const 
    {
        return code[index];
    }

    private:
    int code[3];
};

struct personNode
{
    Person* data;
    personNode* link;
};
typedef personNode* Perptr;

void PersonSorted(Perptr&, Perptr);
void ReadFile_Person(char, Perptr&, Perptr&);

void BookSorted(Bookptr&, Bookptr);
void ReadFile_Book(char, Bookptr&, Bookptr&, Bookptr&);

void Menu(Perptr person[], Bookptr book[]);
void MenuOne(Bookptr search[]);

void MenuTwo(Perptr p_search[], Bookptr b_search[]);

void MenuThree(Perptr p_search[], Bookptr b_search[]);

void MenuFour(Perptr p_search[], Bookptr b_search[]);

void MenuFive(Bookptr b_search[]);

string MenuFivePrint();
