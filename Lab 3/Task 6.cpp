#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* child;
    Node(int val) 
    {
        data = val;
        next = nullptr;
        child = nullptr;
    }
};

class MultiLevelList{
public:
    Node* head;
    MultiLevelList() 
    {
        head = nullptr;
    }
    Node* createNode(int val) 
    {
        return new Node(val);
    }
    Node* buildList(int n) 
    {
        if (n <= 0) 
        {
            return nullptr;
        }
        int val;
        cout << "Enter " << n << " elements: ";
        cin >> val;
        Node* head = new Node(val);
        Node* curr = head;
        for (int i = 1; i < n; i++) 
        {
            cin >> val;
            curr->next = new Node(val);
            curr = curr->next;
        }
        return head;
    }

    void display(Node* head) 
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

    Node* flatten(Node* head) 
    {
        if (!head)
        {
            return nullptr;
        }
        Node* curr = head;
        while (curr) 
        {
            if (curr->child) 
            {
                Node* nextNode = curr->next;
                curr->next = curr->child;
                curr->child = nullptr;
                Node* temp = curr->next;
                while (temp->next)
                {
                    temp = temp->next;
                }
                temp->next = nextNode;
            }
            curr = curr->next;
        }
        return head;
    }
};

int main()
{
    MultiLevelList list;

    int n;
    cout << "Enter number of nodes in main list: ";
    cin >> n;
    Node* head = list.buildList(n);

    Node* curr = head;
    for (int i = 0; i < n; i++) 
    {
        char choice;
        cout << "Does node " << curr->data << " have a child list:y/n: ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') 
        {
            int m;
            cout << "Enter number of nodes in child list of " << curr->data << ": ";
            cin >> m;
            curr->child = list.buildList(m);
        }
        curr = curr->next;
    }

    cout << "Flattened List: ";
    Node* flat = list.flatten(head);
    list.display(flat);
    return 0;
}
