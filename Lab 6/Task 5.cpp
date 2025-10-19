#include <iostream>
#include <stack>
using namespace std;

int precedence(char op) 
{
    if (op == '^') 
    {
        return 3;
    }
    if (op == '*' || op == '/') 
    {
        return 2;
    }
    if (op == '+' || op == '-')
    {
        return 1;
    }
    return 0;
}

bool isDigit(char ch) 
{
    return ch >= '0' && ch <= '9';
}

bool isAlphabet(char ch) 
{
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

int power(int base, int exp) 
{
    int result = 1;
    for (int i = 0; i < exp; i++)
    {
        result *= base;
    }
    return result;
}

string infixToPostfix(string infix) 
{
    stack<char> s;
    string postfix = "";
    for (int i = 0; i < infix.length(); i++) 
    {
        char ch = infix[i];

        if (isDigit(ch) || isAlphabet(ch)) 
        {
            postfix += ch;
        }
        else if (ch == '(') 
        {
            s.push(ch);
        }
        else if (ch == ')') 
        {
            while (!s.empty() && s.top() != '(') 
            {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty()) s.pop();
        }
        else 
        {
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) 
            {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.empty()) 
    {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

int evaluatePostfix(string postfix) 
{
    stack<int> s;
    for (int i = 0; i < postfix.length(); i++) 
    {
        char ch = postfix[i];
        if (isDigit(ch)) 
        {
            s.push(ch - '0');
        } 
        else 
        {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();
            switch (ch) 
            {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                case '^': s.push(power(val1, val2)); break;
            }
        }
    }
    return s.top();
}

int main() 
{
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;
    cout << "Evaluated result: " << evaluatePostfix(postfix) << endl;

    return 0;
}
