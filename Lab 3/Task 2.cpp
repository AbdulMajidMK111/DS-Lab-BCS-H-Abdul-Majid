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

class LinkedList{
public:
    Node* head;
    LinkedList() 
    {
        head = nullptr;
    }

    void insert(int val) 
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

    static Node* mergeSorted(Node* a, Node* b) 
    {
        if (!a) 
        {
            return b;
        }
        if (!b) 
        {
            return a;
        }
        Node* head = nullptr;
        if (a->data <= b->data) 
        {
            head = a;
            a = a->next;
        } 
        else 
        {
            head = b;
            b = b->next;
        }
        Node* tail = head;
        while (a && b) 
        {
            if (a->data <= b->data) 
            {
                tail->next = a;
                a = a->next;
            } 
            else 
            {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        if (a) 
        {
            tail->next = a;
        }
        if (b) 
        {
            tail->next = b;
        }
        return head;
    }
};

int main() 
{
    LinkedList listA, listB, result;
    int n, m, val;

    cout << "Enter number of elements in List A: ";
    cin >> n;
    cout << "Enter elements of List A: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> val;
        listA.insert(val);
    }

    cout << "Enter number of elements in List B: ";
    cin >> m;
    cout << "Enter elements of List B: ";
    for (int i = 0; i < m; i++) 
    {
        cin >> val;
        listB.insert(val);
    }

    cout << "List A: ";
    listA.display();
    cout << "List B: ";
    listB.display();

    result.head = LinkedList::mergeSorted(listA.head, listB.head);

    cout << "Merged List: ";
    result.display();
    return 0;
}
