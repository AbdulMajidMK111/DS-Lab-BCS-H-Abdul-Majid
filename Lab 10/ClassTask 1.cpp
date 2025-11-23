#include <iostream>
#include <string>
using namespace std;

class Patient {
public:
    string name;
    int severity;
    int arrivalTime;
    Patient* next;

    Patient(string n, int s, int a) 
    {
        name = n;
        severity = s;
        arrivalTime = a;
        next = nullptr;
    }
};

class HospitalQueue {
private:
    Patient* head;
    int arrivalCounter;

public:
    HospitalQueue() 
    {
        head = nullptr;
        arrivalCounter = 0;
    }

    void addPatient(string name, int severity) 
    {
        Patient* p = new Patient(name, severity, arrivalCounter++);
        if (!head) 
        {
            head = p;
            cout << "Patient added" << endl;
            return;
        }

        if (p->severity > head->severity ||
            (p->severity == head->severity && p->arrivalTime < head->arrivalTime)) 
            {
            p->next = head;
            head = p;
            cout << "Patient added.\n";
            return;
        }

        Patient* temp = head;
        while (temp->next &&
              (temp->next->severity > p->severity ||
              (temp->next->severity == p->severity &&
               temp->next->arrivalTime < p->arrivalTime))) 
               {
            temp = temp->next;
        }

        p->next = temp->next;
        temp->next = p;
        cout << "Patient added" << endl;
    }

    void getNextPatient() 
    {
        if (!head) 
        {
            cout << "No patients waiting" << endl;
            return;
        }
        Patient* p = head;
        head = head->next;

        cout << "\nNext patient to treat: " << endl;
        cout << "Name: " << p->name
             << "\nSeverity: " << p->severity
             << "\nArrival Time: " << p->arrivalTime << endl;
        delete p;
    }

    void updateSeverity(string name, int newSeverity) 
    {
        if (!head) 
        {
            cout << "No patients in queue" << endl;
            return;
        }

        Patient* prev = nullptr;
        Patient* curr = head;
        bool found = false;

        while (curr) 
        {
            if (curr->name == name) 
            {
                found = true;
                if (prev) 
                {
                    prev->next = curr->next;
                }
                else
                {
                    head = curr->next;
                }

                curr->severity = newSeverity;
                curr->next = nullptr;
                reinsert(curr);
                cout << "Severity updated" << endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        cout << "Patient not found" << endl;
    }

    void reinsert(Patient* p) 
    {
        if (!head) 
        {
            head = p;
            return;
        }

        if (p->severity > head->severity ||
            (p->severity == head->severity && p->arrivalTime < head->arrivalTime)) 
            {
            p->next = head;
            head = p;
            return;
        }

        Patient* temp = head;
        while (temp->next &&
              (temp->next->severity > p->severity ||
              (temp->next->severity == p->severity &&
               temp->next->arrivalTime < p->arrivalTime))) 
               {
            temp = temp->next;
        }

        p->next = temp->next;
        temp->next = p;
    }

    void displayAll() 
    {
        if (!head) 
        {
            cout << "No patients waiting" << endl;
            return;
        }

        cout << "\nPatients (High → Low Priority):" << endl;
        Patient* temp = head;
        while (temp) 
        {
            cout << temp->name << " | Severity: " << temp->severity
                 << " | Arrival: " << temp->arrivalTime << endl;
            temp = temp->next;
        }
    }
};

int main() 
{
    HospitalQueue hq;
    int choice;

    while (true) 
    {
        cout << "1. Add Patient" << endl;
        cout << "2. Get Next Patient" << endl;
        cout << "3. Update Severity" << endl;
        cout << "4. Display All Patients" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) 
        {
            string name;
            int severity;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter severity (1-10): ";
            cin >> severity;
            hq.addPatient(name, severity);
        }
        else if (choice == 2) 
        {
            hq.getNextPatient();
        }
        else if (choice == 3) 
        {
            string name;
            int severity;
            cout << "Enter patient name: ";
            cin >> name;
            cout << "Enter new severity: ";
            cin >> severity;
            hq.updateSeverity(name, severity);
        }
        else if (choice == 4) 
        {
            hq.displayAll();
        }
        else if (choice == 5) 
        {
            break;
        }
        else 
        {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
