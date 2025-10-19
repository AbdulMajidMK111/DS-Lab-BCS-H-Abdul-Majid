#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node(string val) 
    {
        data = val;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;
public:
    Stack() 
    {
        top = nullptr;
    }

    void push(string value) 
    {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << value << " visited" << endl;
    }

    void pop() 
    {
        if (top == nullptr) 
        {
            cout << "No previous page" << endl;
        } 
        else 
        {
            cout << "Going back from " << top->data << endl;
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void peek() 
    {
        if (top == nullptr)
        {
            cout << "No current page" << endl;
        }
        else
        {
            cout << "Current page: " << top->data << endl;
        }
    }

    void display() 
    {
        if (top == nullptr) 
        {
            cout << "No browsing history" << endl;
        } 
        else 
        {
            cout << "Browsing history: ";
            Node* temp = top;
            while (temp != nullptr) 
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() 
{
    Stack history;
    int choice;
    string page;

    while (true) 
    {
        cout << "\nBrowser Navigation Menu" << endl;
        cout << "1. Visit new page" << endl;
        cout << "2. Go back" << endl;
        cout << "3. Show current page" << endl;
        cout << "4. Show history" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            cout << "Enter page URL: ";
            cin >> page;
            history.push(page);
            break;
        case 2:
            history.pop();
            break;
        case 3:
            history.peek();
            break;
        case 4:
            history.display();
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    }
}
