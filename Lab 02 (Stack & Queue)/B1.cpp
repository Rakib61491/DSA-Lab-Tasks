// Write a function that checks if a string made up of brackets — (), {}, and [] — is valid. A string is valid if:
// 1. Every opening bracket has a matching closing bracket.
// 2. Brackets close in the correct order (the last opened one must be closed first).
// Example:
// 1. "()" → true
// 2. "(){}[]" → true
// 3. "(]" → false
// 4. "([)]" → false
// 5. "{[]}" → true
#include<iostream>
using namespace std;
#define MAX 10000

class Stack{
    char* ch;
    int top;
    int size;
public:
    Stack(){
        size = MAX;
        ch = new char[size];
        top = -1;
    }

    void push(char b){
        if(top == size+1){
            cout << "Stack Overflow\n";
            return;
        }
        ch[++top] = b;
    }

    void pop(){
        if(top==-1){
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    bool isEmpty(){
        return top==-1;
    }

    char peek(){
        if(top!=-1)
            return ch[top];
        return 0;
    }

};


int main(){
    // '(' --> 40, ')' --> 41
    // '{' --> 123, '}' --> 125
    // '[' --> 91, ']' --> 93
    string s;
    getline(cin, s);

    Stack checker;

    for(char c:s){
        // cout << c << " " << checker.peek() << endl;    // To Show live status of iteration
        if(c == checker.peek()+1 || c == checker.peek()+2){
            checker.pop();
            // cout << "POP\n";
        }
        else{
            checker.push(c);
            // cout << "PUSH\n";
        }
    }

    if(checker.isEmpty())
        cout << "TRUE\n";
    else
        cout << "FALSE\n";
}


