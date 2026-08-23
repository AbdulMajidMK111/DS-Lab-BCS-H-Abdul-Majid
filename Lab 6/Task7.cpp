/* Task#7:
Application of Stack & Queue (Advanced):
Design a job scheduling system where:
1. Processes (with IDs & priorities) arrive and are stored in a queue.
2. Execution order is determined using a stack (LIFO execution of high-priority tasks).
3. Demonstrate how both queue (arrival order) and stack (execution handling) are
combined. */

#include <iostream>
using namespace std;

struct Process
{
    int id;
    int priority;
};

class Queue {
private:
    Process arr[10];
    int front;
    int rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return rear == 9;
    }

    void enqueue(Process p)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }

        if (front == -1)
        {
            front = 0;
        }

        rear++;
        arr[rear] = p;
    }

    Process dequeue()
    {
        Process p = {-1, -1};

        if (isEmpty())
        {
            return p;
        }

        p = arr[front];

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }

        return p;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "\nArrival Queue: " << endl;

        for (int i = front; i <= rear; i++)
        {
            cout << "Process ID: " << arr[i].id
                 << " | Priority: " << arr[i].priority << endl;
        }
    }
};

class Stack {
private:
    Process arr[10];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == 9;
    }

    void push(Process p)
    {
        if (isFull())
        {
            cout << "Stack is full" << endl;
            return;
        }

        top++;
        arr[top] = p;
    }

    Process pop()
    {
        Process p = {-1, -1};

        if (isEmpty())
        {
            return p;
        }

        p = arr[top];
        top--;

        return p;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "\nExecution Stack: " << endl;

        for (int i = top; i >= 0; i--)
        {
            cout << "Process ID: " << arr[i].id
                 << " | Priority: " << arr[i].priority << endl;
        }
    }
};

int main()
{
    Queue q;
    Stack s;

    Process p1 = {1, 3};
    Process p2 = {2, 8};
    Process p3 = {3, 5};
    Process p4 = {4, 9};
    Process p5 = {5, 2};

    q.enqueue(p1);
    q.enqueue(p2);
    q.enqueue(p3);
    q.enqueue(p4);
    q.enqueue(p5);

    cout << "Processes arriving in the system: " << endl;

    q.display();

    cout << "\nMoving high-priority processes from Queue to Stack" << endl;

    while (!q.isEmpty())
    {
        Process p = q.dequeue();

        if (p.priority >= 5)
        {
            s.push(p);
        }
    }

    s.display();

    cout << "\nExecution Order (LIFO): " << endl;

    while (!s.isEmpty())
    {
        Process p = s.pop();

        cout << "Executing Process ID: " << p.id
             << " | Priority: " << p.priority << endl;
    }
    return 0;
}
