#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

#define MAX 100

template <class T>
class Stack
{
private:
    T arr[MAX];
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
        return top == MAX - 1;
    }

    void push(T x)
    {
        if (!isFull())
            arr[++top] = x;
    }

    T pop()
    {
        if (isEmpty())
            return T();

        return arr[top--];
    }

    T peek()
    {
        if (isEmpty())
            return T();

        return arr[top];
    }
};

class Queue
{
private:
    int arr[MAX];
    int front;
    int rear;

public:
    Queue()
    {
        front = 0;
        rear = -1;
    }

    bool isEmpty()
    {
        return front > rear;
    }

    void enqueue(int x)
    {
        arr[++rear] = x;
    }

    int dequeue()
    {
        return arr[front++];
    }
};

int precedence(char ch)
{
    if (ch == '^')
        return 3;

    if (ch == '*' || ch == '/')
        return 2;

    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

bool isOperand(char ch)
{
    return (ch >= '0' && ch <= '9') ||
           (ch >= 'A' && ch <= 'Z') ||
           (ch >= 'a' && ch <= 'z');
}

void reverse(char exp[])
{
    int n = strlen(exp);

    for (int i = 0; i < n / 2; i++)
    {
        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }
}

void infixToPostfix(char infix[], char postfix[])
{
    Stack<char> st;
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];

        if (ch == ' ')
            continue;

        if (isOperand(ch))
        {
            postfix[k++] = ch;
        }
        else if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            while (!st.isEmpty() && st.peek() != '(')
                postfix[k++] = st.pop();

            st.pop();
        }
        else
        {
            while (!st.isEmpty() &&
                   precedence(st.peek()) >= precedence(ch))
            {
                postfix[k++] = st.pop();
            }

            st.push(ch);
        }
    }

    while (!st.isEmpty())
        postfix[k++] = st.pop();

    postfix[k] = '\0';
}

void infixToPrefix(char infix[], char prefix[])
{
    reverse(infix);

    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    char postfix[MAX];

    infixToPostfix(infix, postfix);

    reverse(postfix);

    strcpy(prefix, postfix);
}

int calculate(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;

    case '-':
        return a - b;

    case '*':
        return a * b;

    case '/':
        return a / b;

    case '^':
        return pow(a, b);
    }

    return 0;
}

int evaluatePostfix(char postfix[])
{
    Stack<int> st;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char ch = postfix[i];

        if (ch >= '0' && ch <= '9')
        {
            st.push(ch - '0');
        }
        else
        {
            int b = st.pop();
            int a = st.pop();

            st.push(calculate(a, b, ch));
        }
    }

    return st.pop();
}

int evaluatePrefix(char prefix[])
{
    Stack<int> st;

    int n = strlen(prefix);

    for (int i = n - 1; i >= 0; i--)
    {
        char ch = prefix[i];

        if (ch >= '0' && ch <= '9')
        {
            st.push(ch - '0');
        }
        else
        {
            int a = st.pop();
            int b = st.pop();

            st.push(calculate(a, b, ch));
        }
    }

    return st.pop();
}

int main()
{
    char infix[MAX];
    char postfix[MAX];
    char prefix[MAX];

    cout << "Enter Infix Expression: ";
    cin >> infix;

    char temp[MAX];
    strcpy(temp, infix);

    infixToPostfix(infix, postfix);
    infixToPrefix(temp, prefix);

    cout << "Postfix = " << postfix << endl;
    cout << "Prefix  = " << prefix << endl;

    return 0;
}