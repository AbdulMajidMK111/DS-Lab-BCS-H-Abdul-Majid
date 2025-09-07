#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val) 
    {
        data = val;
        next = nullptr;
    }
};

class List{
    Node* head;
public:
    List() 
    {
        head = nullptr;
    }

    void insertEnd(int val) 
    {
        Node* newNode = new Node(val);
        if (!head) 
        {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display() 
    {
        Node* temp = head;
        while (temp) 
        {
            cout << temp->data;
            if (temp->next)
            {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    bool isPalindrome() 
    {
        if (!head || !head->next)
        {
            return true;
        }

        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) 
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* prev = nullptr;
        Node* curr = slow;
        while (curr) 
        {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        Node* first = head;
        Node* second = prev;
        while (second) 
        {
            if (first->data != second->data)
            {
                return false;
            }
            first = first->next;
            second = second->next;
        }
        return true;
    }
};

int main() 
{
    List l;
    int n, val;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> val;
        l.insertEnd(val);
    }

    cout << "Linked List: ";
    l.display();

    if (l.isPalindrome())
    {
        cout << "Is Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome" << endl;
    }
    return 0;
}
