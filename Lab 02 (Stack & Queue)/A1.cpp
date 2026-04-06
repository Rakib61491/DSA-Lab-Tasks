// Given a deck of n cards 1 to n from top to bottom. You have to discard the top element and then the new top element , 
// place it to the bottom and continue the process until 1 element is remaining. print the last one element ...
// example: n=6,
// 1,2,3,4,5,6(Top to bottom, top=1, bottom=6)
// 2,3,4,5,6 (del top==1)
// 3,4,5,6,2 (top-->bottom)
// 4,5,6,2 (del top==3)
// 5,6,2,4 (top-->bottom)
// 6,2,4 (del top==5)
// 2,4,6 (top-->bottom)
// 4,6 (del top==2)
// 6,4 (top-->bottom)
// 4 (del top==6)
#include<iostream>
using namespace std;

class Queue{
    int top;
    int bottom;
    int size;
    int* arr;
public:
    Queue(int arr2[], int n){
        size = n, top=0, bottom=n-1;
        arr = new int(size);
        for(int i=0; i<n; i++)
            arr[i] = arr2[i];
    }
    ~Queue(){
        delete[] arr;
    }

    void pop(){
        if(top<bottom){
            top++;
        }
        return;
    }

    void shifting(){
        int buffer = arr[top];
        for(int i=top; i<bottom; i++)
            arr[i] = arr[i+1];
        arr[bottom] = buffer;
    }

    void display(){
        for(int i=top; i<=bottom; i++)
            cout << arr[i] << " ";
        cout << endl;
        return;
    }

    void shuffle(){
        while(top!=bottom){
            pop();
            shifting();
        }    
        cout << "Last Card : " << arr[top] << endl;  
    }
};


int main(){
    int n;
    cout << "Number of Card : ";
    cin >> n;
    int arr[n];
    cout << "Give the cards : ";
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    Queue q(arr, n);
    q.shuffle();
}