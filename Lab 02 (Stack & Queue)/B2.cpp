// Suppose, you are building a text processing game engine, that can identify "mirror word".  Make a function called is_palindrome(text) that checks if a given string is a palindrome.
// 1. A palindrome reads the same forward and backward.
// 2. Ignore spaces, punctuation, and capitalization when checking.
// 3. You must use a stack to solve it.
// 4. Return True if the string is a palindrome, otherwise return False.
// Example:
// Input: "A man, a plan, a canal: Panama"
// Output: True
// (Because when cleaned up, it becomes "amanaplanacanalpanama", which is the same forward and backward.)


#include<iostream>
#include<string>
#define MAX 10000
using namespace std;

class Stack{
    int size;
    int top;
    char* text;
public:
    Stack(){
        size = MAX, top = -1;
        text = new char[size];
    }
    ~Stack(){
        delete[] text;
    }

    void push(char ch){
        if(top<size-1)
            text[++top] = ch;
        else
            cout << "Stack Overflow\n";
        return;
    }

    bool is_palindrome(){
        int n = top + 1;
        for(int i=0; i<=n/2; i++){
            // cout << i << " " << text[i] << " " << text[top-i] << "    ";
            if(text[i] != text[top-i]){
                return false;
            }
        }        return true;
    }
};

int main(){
    string text;
    // cin >> text;
    getline(cin, text);    // To take space in string if exists

    Stack game_engine;
    for(char c:text){
        if((c>='a' && c<='z') || (c>='A' && c<='Z')){
            game_engine.push(tolower(c));
        }
    }
    if(game_engine.is_palindrome())
        cout << "True\n";
    else    
        cout << "False\n";
}