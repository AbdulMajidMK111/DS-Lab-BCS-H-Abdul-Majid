/* Task#1:
Suppose you are developing a bank account management system, and you have defined the
BankAccount class with the required constructors. You need to demonstrate the use of these
constructors in various scenarios.
1. Default Constructor Usage: Create a default-initialized BankAccount object named
account1. Print out the balance of account1.
2. Parameterized Constructor Usage: Create a BankAccount object named account2 with
an initial balance of $1000. Print out the balance of account2.
3. Copy Constructor Usage: Using the account2 you created earlier, create a new
BankAccount object named account3 using the copy constructor. Deduct $200 from
account3 and print out its balance. Also, print out the balance of account2 to ensure it
hasn't been affected by the transaction involving account3. */

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
