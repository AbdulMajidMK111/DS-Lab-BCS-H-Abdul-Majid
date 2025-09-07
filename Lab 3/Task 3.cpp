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

    static Node* reverseInGroups(Node* head, int k) 
    {
        if (!head) 
        {
            return nullptr;
        }
        Node* curr = head;
        Node* prev = nullptr;
        Node* next = nullptr;
        int count = 0;
        while (curr && count < k) 
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (next) 
        {
            head->next = reverseInGroups(next, k);
        }
        return prev;
    }
};

int main() 
{
    LinkedList list;
    int n, val, k;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> val;
        list.insert(val);
    }
    cout << "Enter size of k: ";
    cin >> k;
    cout << "Original List: ";
    list.display();
    list.head = LinkedList::reverseInGroups(list.head, k);
    cout << "Reversed: ";
    list.display();
    return 0;
}
