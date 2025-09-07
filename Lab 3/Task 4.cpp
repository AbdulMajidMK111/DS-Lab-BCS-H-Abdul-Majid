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

class CircularList{
public:
    Node* head;
    CircularList() 
    {
        head = nullptr;
    }

    void create(int n) 
    {
        if (n <= 0) 
        {
            return;
        }
        head = new Node(1);
        Node* prev = head;
        for (int i = 2; i <= n; i++) 
        {
            Node* temp = new Node(i);
            prev->next = temp;
            prev = temp;
        }
        prev->next = head;
    }

    int josephus(int k) 
    {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr->next != curr) 
        {
            for (int count = 1; count < k; count++) 
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            Node* del = curr;
            curr = curr->next;
            delete del;
        }
        int survivor = curr->data;
        delete curr;
        return survivor;
    }
};

int main() 
{
    int n, k;
    cout << "Enter number of people: ";
    cin >> n;
    cout << "Enter step size: ";
    cin >> k;
    CircularList clist;
    clist.create(n);
    cout << "Survivor Position: " << clist.josephus(k) << endl;
    return 0;
}
