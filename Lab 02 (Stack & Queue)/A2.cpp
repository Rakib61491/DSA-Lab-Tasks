// Question : Implement a 'MovingAverage' class that calculates the average of integers in a sliding window of size 'N'. The class should have a constructor to set the window size and a method 'next(val)' that adds a new number, removes the oldest if needed, and returns the current average.

#include<iostream>
using namespace std;
#define MAX 100000
class MovingAverage{    // Queue
    int *arr;
    int size;
    int capacity;
    int top;
    int bottom;
public:
    MovingAverage(int n){
        arr = new int[MAX];
        capacity = n, size = MAX, top = -1, bottom = 0;
    }

    ~MovingAverage(){
        delete[] arr;
    }
 
    bool isEmpty(){
        return bottom > top;
    }

    bool isFull(){
        return top == size-1;
    }

    void display(){
        if(isEmpty()){
            cout << "No element\n";
            return;
        }
        for (int i = bottom; i <= top; i++)
            cout << arr[i] << " ";
        cout << endl;
        return;    
    }

    void push(int val){
        if(!isFull())
            arr[++top] = val;
        else
            cout << "Queue Overflow\n";
        return;
    }

    void pop(){
        if(!isEmpty())
            bottom++;
        else
            cout << "Queue Underflow\n";
        return;
    }

    void next(int val){
        if(top-bottom >= capacity-1)
            pop();
        push(val);
        display();
        int sum=0;
        for (int i = bottom; i <=top; i++)
            sum+=arr[i];
        cout << sum / (float)(top-bottom+1) << endl;       
    }
};


int main(){
    int n;
    cout << "Enter the size of Sliding Window : ";
    cin >> n;
    
    MovingAverage obj(n);

    while(true){
        int val;
        cout << "Enter the Integer: ";
        cin >> val;
        obj.next(val);
    }
}