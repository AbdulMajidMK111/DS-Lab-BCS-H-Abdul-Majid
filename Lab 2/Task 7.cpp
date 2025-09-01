#include <iostream>
using namespace std;

int main() 
{
    int departments;
    cout << "Enter number of departments: ";
    cin >> departments;

    int** salaries = new int*[departments];
    int* empCount = new int[departments];

    for (int i = 0; i < departments; i++) 
    {
        cout << "\nEnter number of employees in department " << i + 1 << ": ";
        cin >> empCount[i];
        salaries[i] = new int[empCount[i]];

        cout << "Enter salaries of employees in department " << i + 1 << ": " << endl;
        for (int j = 0; j < empCount[i]; j++) 
        {
            cin >> salaries[i][j];
        }
    }

    cout << "\nHighest salary in each department: " << endl;
    for (int i = 0; i < departments; i++) 
    {
        int maxSalary = salaries[i][0];
        for (int j = 1; j < empCount[i]; j++) 
        {
            if (salaries[i][j] > maxSalary) 
            {
                maxSalary = salaries[i][j];
            }
        }
        cout << "Department " << i + 1 << ": " << maxSalary << endl;
    }

    double maxAvg = -1;
    int deptIndex = -1;

    for (int i = 0; i < departments; i++) 
    {
        int sum = 0;
        for (int j = 0; j < empCount[i]; j++) 
        {
            sum += salaries[i][j];
        }
        double avg = (double)sum / empCount[i];

        if (avg > maxAvg) 
        {
            maxAvg = avg;
            deptIndex = i;
        }
    }

    cout << "\nDepartment with maximum average salary: " << deptIndex + 1 << " (Average = " << maxAvg << ")" << endl;

    for (int i = 0; i < departments; i++) 
    {
        delete[] salaries[i];
    }
    delete[] salaries;
    delete[] empCount;
    return 0;
}
