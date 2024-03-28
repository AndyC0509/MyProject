#include "CS03AProject2.cpp"

int main ()
{
    char book_file[20] = " ";
    char person_file[20] = " ";

    cout << "Please enter book file : ";
    cin >> book_file;
    cout << "Please enter person file : ";
    cin >> person_file;
    Bookptr children =NULL, computer = NULL, novel = NULL;
    Perptr teacher = NULL, student = NULL;
    
    ReadFile_Book(book_file, children, computer, novel);
    ReadFile_Person(person_file, teacher, student);
    
    Bookptr library[MAXBOOK] = {children, computer, novel};
    Perptr person[MAXPERSON] = {teacher, student};

    Menu(person, library);
    return 0;

}
