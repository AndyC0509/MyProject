#include "CS03AProject2.h"

//Sort the person by their ID
void PersonSorted(Perptr& head, Perptr p) 
{
    if (!head || p->data->getID() < head->data->getID()) 
    {
        p->link = head;
        head = p;
    } 
    else 
    {
        Perptr current = head;
        while (current->link && current->link->data->getID() < p->data->getID()) 
        {
            current = current->link;
        }
        p->link = current->link;
        current->link = p;
    }
}

//Read the Person.txt
void ReadFile_Person(char file[], Perptr& head1, Perptr& head2)
{
    ifstream infile;
    infile.open(file);
    if(infile.fail())
	{
		cout << "Input file opening failed. "<<endl;
		exit(1);
	}
    int p_id, book_count;
    int book1 = 0, book2 = 0, book3 = 0;
    string p_name;

    head1 = NULL;
    head2 = NULL;

    Perptr current1 = head1;
    Perptr current2 = head2;
    Perptr ptr = NULL;
    
    while(!infile.eof())
	{
        infile >> p_id >> p_name >> book_count;
        current1 = head1;
        current2 = head2;  
        ptr = new personNode;
        ptr -> link = NULL;
        if(p_id >= 1 && p_id <= 100)
        {
            switch(book_count)
            {
                case 1:
                infile >> book1;
                break;
                case 2:
                infile >> book1 >> book2;
                break;
                case 3:
                infile >> book1 >> book2 >> book3;
                break;
            }

            ptr -> data = new Teacher(p_id, p_name, book_count, book1, book2, book3);

            PersonSorted(head1,ptr);
        }
        else if(p_id >= 101 && p_id <= 300)
        {
            
            switch(book_count)
            {
                case 1:
                infile >> book1;
                break;
                case 2:
                infile >> book1 >> book2;
                break;
            }

            ptr -> data = new Student(p_id, p_name, book_count, book1, book2);

            PersonSorted(head2,ptr);
        }
	}
    infile.close();
}

//Sort the books by their book code
void BookSorted(Bookptr& head, Bookptr p) 
{
    if(!head || p->data->get_bookCode() < head-> data->get_bookCode())
    {
        p->link = head;
        head = p;
    }
    else 
    {
        Bookptr current = head;
        while (current->link && current->link->data->get_bookCode() < p->data->get_bookCode())
        {
            current = current -> link;
        }
        p -> link = current -> link; 
        current -> link = p;
    }
}

//Read Book file
void ReadFile_Book(char file[], Bookptr& head1, Bookptr& head2, Bookptr& head3)
{
    ifstream infile;
    infile.open(file);
    if(infile.fail())
	{
		cout << "Input file opening failed. "<<endl;
		exit(1);
	}

    int b_code, b_available, b_rented;
    int b_age, b_pdate;
    string b_name, b_p;

    head1 = NULL;
    head2 = NULL;
    head3 = NULL;

    Bookptr current1 = head1;
    Bookptr current2 = head2;
    Bookptr current3 = head3;

    Bookptr ptr = NULL;
    
    while(!infile.eof())
	{
        infile >> b_code >> b_name;
        current1 = head1;
        current2 = head2;
        current3 = head3;
        ptr = new bookNode;
        ptr -> link = NULL;

        if(b_code >= 1001 && b_code <= 2000)
        {
            infile >> b_age >> b_available >> b_rented; 
            ptr -> data = new ChildrenBook(b_code, b_name, b_available, b_rented, b_age);

            BookSorted(head1, ptr);
            //cout << "Read Children book: " << b_name << " with code: " << b_code << endl;
        }

        else if(b_code >= 2001 && b_code <= 3000)
        {
            infile >> b_p >>b_available >> b_rented; 
            ptr -> data = new ComputerBook(b_code, b_name, b_available, b_rented, b_p);
            
            BookSorted(head2, ptr);
            //cout << "Read Computer book: " << b_name << " with code: " << b_code << endl;
        }

        else
        {
            infile >> b_pdate >> b_available >> b_rented; 
            ptr -> data = new Novel(b_code, b_name, b_available, b_rented, b_pdate);
            
            BookSorted(head3, ptr);
            //cout << "Read Novel book: " << b_name << " with code: " << b_code << endl;
        }
        
	}
    infile.close();
}

//Print Menu
void Menu(Perptr person[], Bookptr book[])
{
    int number;
    do
    {
        try
        {
            cout << "-------------------------------"<<endl<<setw(17)<<"Menu"<<endl<<"-------------------------------"<<endl;
            cout << "1. Search a book\n"<<"2. Rent a book\n"<<"3. Return a book\n"<<"4. Show my information\n"<<"5. Show all books\n"<<"6. Exit";
            cout << endl<<"Select(1~6) : ";
            cin >> number;
            cout << endl;
            if(number <=0 || number > 6)
            {
                throw "Input number invaild";
            }
            
            switch(number)
            {
                case 1:
                MenuOne(book);
                break;
                case 2:
                MenuTwo(person, book);
                break;
                case 3:
                MenuThree(person, book);
                break;
                case 4:
                MenuFour(person, book);
                break;
                case 5:
                MenuFive(book);
                break;
                case 6:
                cout << "Exiting!...";
                return;
        }
        }
        catch(const char* msg1)
        {
            cout << msg1 << endl << endl;
        }
    }while (1);
}   

//MenuOne is Search a book
void MenuOne(Bookptr b_search[])
{
    int enternum = 0;
    string entertitle =" ";
    cout << "Enter code : ";
    cin >> enternum;
    cout << "Enter title : ";
    cin >> entertitle;
    cout << endl;

    bool found = false;
    Bookptr b_current = NULL;

    //Search if the book is in the data
    for(int i = 0; i < MAXBOOK; i++)
    {
        Bookptr current = b_search[i];
        while(current)
        {
            if(enternum == current->data->get_bookCode() && entertitle == current->data->getTitle())
            {
                cout << current->data->getTitle() << "(" << enternum<<") exists."<<endl;
                cout << "category : ";
                if(current->data->get_bookCode() >= 1001 && current->data->get_bookCode() <= 2000)
                {
                    cout << "children"<<endl;
                }
                else if (current->data->get_bookCode() <= 3000)
                {
                    cout << "computer"<<endl;
                }
                else
                {
                    cout << "novel"<<endl;
                }
                cout <<"publisher : "<< current->data->getPublisher() << endl;
                cout << current->data->getAva() << " available, "<<current->data->getRented()<<" rented"<<endl<<endl;
                found = true;
                break;
            }
            current = current -> link;
        }
        if(found)break;
    }
    if(!found)
    {
        throw "Book not found";
    } 
}

//Rent a book
void MenuTwo(Perptr p_search[], Bookptr b_search[])
{
    int enternum = 0;
    string entertitle =" ";

    //ask for id
    cout << "Enter id : ";
    cin >> enternum;

    bool foundID = false;

    Perptr p_current = NULL;
    Bookptr b_current = NULL;

    //Search if the person is in the data
    for(int i = 0; i < MAXPERSON; i++)
    {
        foundID = false;
        p_current = p_search[i];
        while(p_current)
        {
            if(enternum == p_current -> data -> getID())
            {
                foundID = true;
                break;
            }
            p_current = p_current -> link;
        }
        if(foundID) break;
    }

    if(!foundID)
    {
        throw "There is not such student";
    }

    cout << "Enter book title : ";
    cin >> entertitle;
    cout << endl;
    bool foundBook = false;

    //Search if the book is in the library
    for(int i = 0; i < MAXBOOK; i++)
    {
        foundBook = false;
        b_current = b_search[i];
        while(b_current)
        {
            if(entertitle == b_current -> data -> getTitle())
            {
                foundBook = true;
                break;
            }
            b_current = b_current -> link;
        }
        if(foundBook) break;
    }

    if(!foundBook)
    {
        throw "There is not such book";
    }

    //Search if student/teacher has the same book
    bool samebook = false;
    if(foundID && foundBook)
    {
        for(int i = 0; i < p_current -> data -> getcount(); i++)
        {
            if(p_current -> data -> getcode(i) == b_current -> data -> get_bookCode())
            {
                samebook = true;
                break;
            }
        }
    }

    if(samebook)
    {
        throw "You have the same book already!";
    }

    //process to rent
    if(!samebook)
    {
        char ans;
        cout << "You are " << p_current -> data -> getName() << ". You rented '"<< p_current -> data -> getcount() <<" book.\n";
        cout <<"Do you want to rent '"<<b_current-> data -> getTitle()<<"' (y/n)? ";
        cin >> ans;

        if(ans=='y' )
        {
            if((p_current -> data -> getcount() < 3 && p_current -> data -> getID() >=1 && p_current -> data -> getID() <= 100)
            ||(p_current -> data -> getcount() < 2 && p_current -> data -> getID() >=101 && p_current -> data -> getID() <= 300))
            {
                int updatecount = p_current -> data -> getcount();
                p_current -> data -> setcount(updatecount+1);
                p_current -> data -> setcode(b_current -> data -> get_bookCode(), updatecount);
                int updatebookava = b_current -> data -> getAva();
                int updatebookrent = b_current -> data -> getRented();
                b_current -> data -> setAva(updatebookava-1);
                b_current -> data -> setRented(updatebookrent+1);
                 
                cout << "***** Rent succeeded. Check your info!"<<endl<<endl;
            }
            else 
            {
                throw "You should return some books first! Come back later!";
            }
        }
        else
        {
            throw "***** Rent failed.";
        }
    }
}

//Return a book
void MenuThree(Perptr p_search[], Bookptr b_search[])
{
    int enter1,enter2;

    cout << "Enter your id    : ";
    cin >> enter1;

    //search if the id matches
    bool foundID;
    Perptr pid_current = NULL;
    for(int i = 0; i < MAXPERSON; i++)
    {
        foundID = false;
        pid_current = p_search[i];
        while(pid_current)
        {
            if(enter1== pid_current -> data -> getID())
            {
                foundID = true;
                break;
            }
            pid_current = pid_current -> link;
        }
        if(foundID) break;
    }

    if(!foundID)
    {
        throw "There is not such student";
    }

    cout << "Enter the book code to return : ";
    cin >> enter2;
    cout << endl;

    //search if the book matches
    bool foundBookcode = false;
    int index = 0;

    if(foundID)
    {
        for(int j = 0; j < pid_current -> data -> getcount(); j++)
        {
            if(enter2 == pid_current -> data -> getcode(j))
            {
                foundBookcode = true;
                index = j;
                break;
            }
        }
    }
    
    if(!foundBookcode)
    {
        throw "There is no such book in your data";
    }
    
    //search if the book is in the person's data
    Bookptr b_current = NULL;
    bool foundBook = false;
    if(foundBookcode)
    {
        for(int i = 0; i < MAXBOOK; i++)
        {
            b_current = b_search[i];
            while(b_current)
            {
                if(pid_current -> data -> getcode(index) == b_current -> data -> get_bookCode())
                {
                    foundBook = true;
                    break;
                }
                b_current = b_current -> link;
            }
        }
    }
    
    if(!foundBook)
    {
        throw "There is no such code in the library";
    }

    

    //if the book is in person's data, put the new data 
    char ans;
    if(foundBook)
    {
        
        char ans;
        cout << "Do you want to return '"<<b_current -> data -> getTitle()<<"' (y/n)? ";
        cin >> ans;

        if(ans=='y' )
        {
            if((pid_current -> data -> getcount() <= 3 && pid_current -> data -> getID() >=1 && pid_current -> data -> getID() <= 100)||(pid_current -> data -> getcount() <= 2 && pid_current -> data -> getID() >=101 && pid_current -> data -> getID() <= 300))
            {
                int updatebookava = b_current -> data -> getAva();
                int updatebookrent = b_current -> data -> getRented();
                b_current -> data -> setAva(updatebookava+1);
                b_current -> data -> setRented(updatebookrent-1);

                pid_current -> data -> returnBook(index);
                int updatecount = pid_current -> data -> getcount();
                pid_current -> data -> setcount(updatecount-1);
                cout << "***** Rent succeeded. Check your info!"<<endl<<endl;
            }
        }
        else
        {
            throw "***** Rent failed.";
        }
        
    }
}

//Show my information
void MenuFour(Perptr p_search[], Bookptr b_search[])
{
    int enter1;

    cout << "Enter your id    : ";
    cin >> enter1;

    bool foundID;
    Perptr p_current = NULL;
    for(int i = 0; i < MAXPERSON; i++)
    {
        foundID = false;
        p_current = p_search[i];
        while(p_current)
        {
            if(enter1== p_current -> data -> getID())
            {
                foundID = true;
                break;
            }
            p_current = p_current -> link;
        }
        if(foundID) break;
    }

    if(!foundID)
    {
        throw "There is not such student";
    }

    string enter2 = "";
    cout << "Enter your name  : ";
    cin >> enter2;
    cout << endl;

    bool foundName = false;
    int index = 0;
    if(enter2 == p_current -> data -> getName())
    {
        foundName = true;
    }
    
    if(!foundName)
    {
        throw "Wrong Name";
    }
    
    Bookptr b_current = NULL;
    if(p_current -> data -> getcount() != 0)
    {
        cout << "You rented " << p_current -> data -> getcount() << " books.\n";
        for(int j = 0; j < MAXBOOK; j++)
        {
            for(int i = 0; i < p_current -> data -> getcount(); i++)
            {
                b_current = b_search[j];
                while(b_current)
                {
                    if(p_current -> data -> getcode(i) == b_current -> data -> get_bookCode())
                    {
                        cout << "* "<<b_current -> data -> getTitle()<<"("<<b_current -> data -> get_bookCode()<<") -"<<endl;
                        break;
                    }
                    b_current = b_current -> link;
                }
            }
        }
        cout << endl;
    }
    else
    {
        throw "You did not rent any book!";
    }
}

//Show all books
void MenuFive(Bookptr b_search[])
{
    Bookptr b_current = NULL;
    for(int i = 0; i < MAXBOOK; i++)
    {
        b_current = b_search[i];
        cout << "============================================================================================================"
        <<endl<< setw(60) << MenuFivePrint()<<endl
        <<"============================================================================================================"<<endl;
        cout << setw(10) << "code"<<setw(30)<<"title";
        if(i == 0)
        {
            cout<<setw(25)<<"age";
        }
        else if(i == 1)
        {
            cout<<setw(30)<<"Publisher";
        }
        else
        {
            cout<<setw(30)<<"Publisher Date";
        }
        cout << setw(20)<<"available"<<setw(15)<<"rented"<<endl;
        cout << "------------------------------------------------------------------------------------------------------------"<<endl;
        
        while(b_current)
        {
            string booknames = b_current->data->getTitle();
            for (int j = 0; booknames[j] != '\0'; j++)
            {
                if (booknames[j] == '_')
                {
                    booknames[j] = ' ';
                }
            }
            string pubnames = b_current->data->getPublisher();
            for (int k = 0; pubnames[k] != '\0'; k++)
            {
                if (pubnames[k] == '-')
                {
                    pubnames[k] = ' ';
                }
            }
            cout << setw(10)<<b_current->data->get_bookCode()<<setw(37)<< booknames;
            if(i == 0)
            {
                cout << setw(17)<<b_current->data->getAge();
                cout << setw(17) << b_current->data->getAva() << setw(17)<<b_current->data->getRented()<<endl;
            }
            if(i == 1)
            {
                cout << setw(23)<< pubnames;
                cout << setw(16) << b_current->data->getAva() << setw(17)<<b_current->data->getRented()<<endl;
            }
            if(i == 2)
            {
                cout << setw(18)<<b_current->data->getPublishDate();
                cout << setw(21) << b_current->data->getAva() << setw(17)<<b_current->data->getRented()<<endl;
            }
            
            b_current = b_current->link;
        }
    }
   cout << endl;
}

//Print the category of books in menu 5
string MenuFivePrint()
{
    static int num = 0;
    string cat;
    switch (num)
    {
        case 0:
        cat = "Children Books";
        break;
        case 1:
        cat = "Computer Books";
        break;
        case 2:
        cat = "Novel";
        break;
    }
    num++;
    return cat;
}

    

 
