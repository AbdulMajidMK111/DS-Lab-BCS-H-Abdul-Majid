#include <iostream>
#include <cstring>
using namespace std;

class Exam{
private:
    char* studentName;
    char* examDate;
    int score;

public:
    Exam(const char* name, const char* date, int sc) 
    {
        studentName = new char[strlen(name) + 1];
        strcpy(studentName, name);

        examDate = new char[strlen(date) + 1];
        strcpy(examDate, date);

        score = sc;
    }

    ~Exam() 
    {
        delete[] studentName;
        delete[] examDate;
        cout << "Destructor called" << endl;
    }

    void setStudentName(const char* name) 
    {
        delete[] studentName;
        studentName = new char[strlen(name) + 1];
        strcpy(studentName, name);
    }

    void setExamDate(const char* date) 
    {
        delete[] examDate;
        examDate = new char[strlen(date) + 1];
        strcpy(examDate, date);
    }

    void setScore(int sc) 
    {
        score = sc;
    }

    void display() const 
    {
        cout << "Student Name: " << studentName << endl;
        cout << "Exam Date: " << examDate << endl;
        cout << "Score: " << score << endl;
    }

};

int main() 
{
    Exam exam1("Amjad", "20-Aug-2025", 78);
    cout << "Original Exam Record:" << endl;
    exam1.display();

    cout << "\nCreating Shallow Copy" << endl;
    Exam exam2 = exam1;

    cout << "Exam2 (copied):" << endl;
    exam2.display();

    return 0;
}
