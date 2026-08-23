#include <iostream>
using namespace std;

int main() 
{
    int n, m;
    cout << "Enter number of days: ";
    cin >> n;
    cout << "Enter number of readings per day: ";
    cin >> m;

    double** temps = new double*[n];
    for (int i = 0; i < n; i++) 
    {
        temps[i] = new double[m];
    }

    for (int i = 0; i < n; i++) 
    {
        cout << "\nEnter temperatures for Day " << i + 1 << ":" << endl;
        for (int j = 0; j < m; j++) 
        {
            cin >> temps[i][j];
        }
    }

    double* dailyAvg = new double[n];
    for (int i = 0; i < n; i++) 
    {
        double sum = 0;
        for (int j = 0; j < m; j++) 
        {
            sum += temps[i][j];
        }
        dailyAvg[i] = sum / m;
    }

    cout << "\nDaily average temperatures:" << endl;
    for (int i = 0; i < n; i++) 
    {
        cout << "Day " << i + 1 << ": " << dailyAvg[i] << endl;
    }

    int hottestDay = 0, coldestDay = 0;
    for (int i = 1; i < n; i++) 
    {
        if (dailyAvg[i] > dailyAvg[hottestDay]) 
        {
            hottestDay = i;
        }
        if (dailyAvg[i] < dailyAvg[coldestDay]) 
        {
            coldestDay = i;
        }
    }

    cout << "\nHottest Day: Day " << hottestDay + 1 << " (Average = " << dailyAvg[hottestDay] << ")" << endl;
    cout << "Coldest Day: Day " << coldestDay + 1 << " (Average = " << dailyAvg[coldestDay] << ")" << endl;

    for (int i = 0; i < n; i++) 
    {
        delete[] temps[i];
    }
    delete[] temps;
    delete[] dailyAvg;
    return 0;
}
