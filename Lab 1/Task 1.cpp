#include <iostream>
using namespace std;

class BankAccount{
private:
    double balance;

public:
    BankAccount() 
    {
        balance = 0.0;
        cout << "Default Constructor" << endl;
    }

    BankAccount(double initialBalance) 
    {
        balance = initialBalance;
        cout << "Parameterized Constructor" << endl;
    }

    BankAccount(const BankAccount &other)
    {
        balance = other.balance;
        cout << "Copy Constructor" << endl;
    }

    void withdraw(double amount) 
    {
        if (amount <= balance) 
        {
            balance -= amount;
        } 
        else 
        {
            cout << "Insufficient ammount" << endl;
        }
    }

    double getBalance() const 
    {
        return balance;
    }
};

int main() 
{
    BankAccount account1; 
    cout << "Balance of account1: $" << account1.getBalance() << endl;

    BankAccount account2(1000); 
    cout << "Balance of account2: $" << account2.getBalance() << endl;

    BankAccount account3(account2); 
    account3.withdraw(200);
    cout << "Balance of account3 (after withdrawing $200): $" << account3.getBalance() << endl;

    cout << "Balance of account2 (unchanged): $" << account2.getBalance() << endl;

    return 0;
}
