#include <iostream>
using namespace std;

class SNode{
public:
    int data;
    SNode* next;
    SNode(int val) 
    {
        data = val;
        next = nullptr;
    }
};

class DNode{
public:
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val) 
    {
        data = val;
        next = prev = nullptr;
    }
};

class SinglyList{
public:
    SNode* head;
    SinglyList() 
    {
        head = nullptr;
    }

    void insert(int val) 
    {
        SNode* newNode = new SNode(val);
        if (!head) 
        {
            head = newNode;
            return;
        }
        SNode* temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display() 
    {
        SNode* temp = head;
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

    DNode* toDoubly() 
    {
        if (!head)
        {
            return nullptr;
        }
        SNode* curr = head;
        DNode* dhead = new DNode(curr->data);
        DNode* dcurr = dhead;
        curr = curr->next;
        while (curr) 
        {
            DNode* newNode = new DNode(curr->data);
            dcurr->next = newNode;
            newNode->prev = dcurr;
            dcurr = newNode;
            curr = curr->next;
        }
        return dhead;
    }

    SNode* toCircular() 
    {
        if (!head) 
        {
            return nullptr;
        }
        SNode* temp = head;
        while (temp->next) 
        {
            temp = temp->next;
        }
        temp->next = head;
        return head;
    }
};

void displayDoubly(DNode* head) 
{
    DNode* temp = head;
    while (temp) 
    {
        cout << temp->data;
        if (temp->next) 
        {
            cout << " <-> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

void displayCircular(SNode* head, int n) 
{
    SNode* temp = head;
    for (int i = 0; i < n; i++) 
    {
        cout << temp->data;
        if (i < n - 1)
        {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << " ->...back to head" << endl;
}

int main() 
{
    SinglyList slist;
    int n, val;
    cout << "Enter number of elements in singly list: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> val;
        slist.insert(val);
    }

    cout << "Singly Linked List: ";
    slist.display();

    DNode* dlist = slist.toDoubly();
    cout << "Doubly Linked List: ";
    displayDoubly(dlist);

    SNode* clist = slist.toCircular();
    cout << "Circular Linked List: ";
    displayCircular(clist, n);
    return 0;
}
