#include <bits/stdc++.h>
using namespace std;

class Stack {
    char *arr;
    int topIndex;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new char[capacity];
        topIndex = -1;
    }

    ~Stack() { delete[] arr; }

    void push(char c) {
        if (topIndex < capacity - 1) arr[++topIndex] = c;
    }

    void pop() {
        if (topIndex >= 0) topIndex--;
    }

    char top() {
        if (topIndex >= 0) return arr[topIndex];
        return '\0';
    }

    bool isEmpty() { return topIndex == -1; }
};

int precedence(char op){
    if(op=='^') return 3;
    if(op=='*'||op=='/') return 2;
    if(op=='+'||op=='-') return 1;
    return 0;
}

void reverseString(char str[], int len){
    int i = 0, j = len-1;
    char temp;
    
    while(i<j){
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

void infixToPrefix(char infix[], char prefix[]){
    int len = strlen(infix);
    reverseString(infix, len);

    for(int i=0; i<len; i++){
        if(infix[i]=='(') infix[i]=')';
        else if(infix[i]==')') infix[i]='(';
    }

    Stack st(len);
    int k = 0;

    for(int i=0; i<len; i++){
        char c = infix[i];
        if(isalpha(c))
            prefix[k++] = c;

        else if(c=='(')
            st.push(c);

        else if(c==')'){
            while(!st.isEmpty() && st.top()!='('){
                prefix[k++] = st.top();
                st.pop();
            }
            st.pop();
        }

        else{
            while(!st.isEmpty() && precedence(st.top())>=precedence(c)){
                prefix[k++] = st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while(!st.isEmpty()){
        prefix[k++] = st.top();
        st.pop();
    }

    prefix[k] = '\0';
    reverseString(prefix, k);
}

int main(){
    char text[500];
    cout << "Enter text: ";
    cin >> text;

    int count = 0;
    int i = 0;

    while(text[i]!='\0'){
        if(text[i]=='{'){
            char infix[100], prefix[100];
            int j = 0;
            i++;

            while(text[i]!='}' && text[i]!='\0'){
                if(text[i]!=' ')
                    infix[j++] = text[i];
                i++;
            }

            infix[j] = '\0';

            infixToPrefix(infix, prefix);

            cout << "Expression " << count+1 << ":\n";
            cout << "Infix: " << infix << "\n";
            cout << "Prefix: " << prefix << "\n\n";

            count++;
        }
        i++;
    }

    cout << "Total expressions found: " << count << "\n";

    return 0;
}