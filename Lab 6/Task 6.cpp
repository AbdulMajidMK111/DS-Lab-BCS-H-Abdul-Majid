#include <iostream>
#include <string>
using namespace std;

class Stack {
    char* arr;
    int top, size;
public:
    Stack(int n) {
        size = n;
        arr = new char[size];
        top = -1;
    }
    void push(char x) {
        if (top < size - 1)
            arr[++top] = x;
    }
    char pop() {
        if (top >= 0)
            return arr[top--];
        return '\0';
    }
    char peek() {
        if (top >= 0)
            return arr[top];
        return '\0';
    }
    bool empty() {
        return top == -1;
    }
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string reverseString(string s) {
    string r = "";
    for (int i = s.length() - 1; i >= 0; i--)
        r += s[i];
    return r;
}

string infixToPrefix(string infix) {
    Stack s(infix.length());
    string prefix = "";

    infix = reverseString(infix);
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            prefix += c;

        else if (c == ')')
            s.push(c);

        else if (c == '(') {
            while (!s.empty() && s.peek() != ')')
                prefix += s.pop();
            if (!s.empty())
                s.pop();
        }

        else if (isOperator(c)) {
            while (!s.empty() && precedence(c) < precedence(s.peek()))
                prefix += s.pop();
            s.push(c);
        }
    }

    while (!s.empty())
        prefix += s.pop();

    prefix = reverseString(prefix);
    return prefix;
}

int evaluatePrefix(string expr) {
    int stack[100];
    int top = -1;

    for (int i = expr.length() - 1; i >= 0; i--) {
        char c = expr[i];
        if (c >= '0' && c <= '9')
            stack[++top] = c - '0';
        else if (isOperator(c)) {
            int op1 = stack[top--];
            int op2 = stack[top--];
            int res = 0;
            if (c == '+') res = op1 + op2;
            else if (c == '-') res = op1 - op2;
            else if (c == '*') res = op1 * op2;
            else if (c == '/') res = op1 / op2;
            else if (c == '^') {
                res = 1;
                for (int j = 0; j < op2; j++)
                    res *= op1; // simple power without cmath
            }
            stack[++top] = res;
        }
    }
    return stack[top];
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string prefix = infixToPrefix(infix);
    cout << "Prefix Expression: " << prefix << endl;
    cout << "Evaluation Result: " << evaluatePrefix(prefix) << endl;

    return 0;
}
