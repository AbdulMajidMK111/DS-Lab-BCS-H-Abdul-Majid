/* Task#3:
Design a program to handle marks of students in different courses using a jagged array
(since each student is enrolled in a different number of courses).
=> Input the number of courses each student takes.
=> Dynamically allocate memory for each student accordingly.
=> Calculate and display each student’s average marks. */

#include <iostream>
using namespace std;

int main() 
{
    int n;  
    cout << "Enter number of students: ";
    cin >> n;

    int* courses = new int[n];      
    int** marks = new int*[n];      

    for (int i = 0; i < n; ++i) 
    {
        cout << "Enter number of courses for student " << i + 1 << ": ";
        cin >> courses[i];
        marks[i] = new int[courses[i]];

        cout << "Enter marks for student " << i + 1 << ":\n";
        for (int j = 0; j < courses[i]; ++j) 
        {
            cout << " Course " << j + 1 << ": ";
            cin >> marks[i][j];
        }
    }

    cout << "\nAverage marks of students: " << endl;
    for (int i = 0; i < n; ++i) 
    {
        int sum = 0;
        for (int j = 0; j < courses[i]; ++j)
        {
            sum += marks[i][j];
        }
        double avg = (courses[i] > 0) ? (double)sum / courses[i] : 0;
        cout << "Student " << i + 1 << ": " << avg << endl;
    }

    for (int i = 0; i < n; ++i) 
    {
        delete[] marks[i];
    }
    delete[] marks;
    delete[] courses;
    return 0;
}
