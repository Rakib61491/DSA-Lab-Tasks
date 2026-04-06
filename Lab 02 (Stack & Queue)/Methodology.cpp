#include <iostream>
using namespace std;

class Stack{
    int *arr;
    int top;
    int max;
public:
    Stack(int size){
        max=size;
        top=-1;
        arr = new int[max];
    }

    ~Stack(){
        delete[] arr;
    }
    
    bool isEmpty(){
        return top == -1;
    }

    void push(int value){
        if (top < max - 1)
            arr[++top] = value;
        else
            cout << "Stack Overflow" << endl;
    }

    void pop(){
        if (!isEmpty())
            top--;
        else
            cout << "Stack Underflow" << endl;
    }

    void displayTop(){
        if(!isEmpty())
            cout << arr[top] << endl;
        else
            cout << "Stact Underflow" << endl;
    }
};


class Queue{
    int *arr;
    int front;
    int rear;
    int max;
public:
    Queue(int size){
        max=size;
        arr = new int[max];
        front=0;
        rear=-1;
    }

    ~Queue(){
        delete[] arr;
    }

    bool isEmpty(){
        return rear < front;
    }

    bool isFull(){
        return rear == max - 1;
    }
    
    void enqueue(int value){
        if (!isFull())
            arr[++rear] = value;
        else
            cout << "Queue Overflow" << endl;
    }

    void dequeue(){
        if (!isEmpty())
            front++;
        else
            cout << "Queue Underflow" << endl;
    }

    void displayFront(){
        if(!isEmpty())
            cout << arr[front] << endl;
        else
            cout << "Queue Underflow" << endl;
    }

    void peek(){
        if(!isEmpty())
            cout << arr[rear] << endl;
        else
            cout << "Queue Underflow" << endl;
    }
};

class Deque{
    int *arr;
    int front;
    int rear;
    int max;
public:
    Deque(int size){
        max=size;
        arr = new int[max];
        front=-1;
        rear=0;
    }

    ~Deque(){
        delete[] arr;
    }

    bool isEmpty(){
        return front == -1;
    }

    bool isFull(){
        return (front == 0 && rear == max - 1) || (front == rear + 1);
    }

    void front_push(int value){
        if (isFull())
            cout << "Deque Overflow" << endl;
        else{
            if (front == -1)
                front = rear = 0;
            else if (front == 0)
                front = max - 1;
            else
                front--;
            arr[front] = value;
        }
    }

    void back_push(int value){
        if (isFull())
            cout << "Deque Overflow" << endl;
        else{
            if (front == -1)
                front = rear = 0;
            else if (rear == max - 1)
                rear = 0;
            else
                rear++;
            arr[rear] = value;
        }
    }

    void front_pop(){
        if (isEmpty())
            cout << "Deque Underflow" << endl;
        else{
            if (front == rear)
                front = rear = -1;
            else if (front == max - 1)
                front = 0;
            else
                front++;
        }
    }
    
    void back_pop(){
        if (isEmpty())
            cout << "Deque Underflow" << endl;
        else{
            if (front == rear)
                front = rear = -1;
            else if (rear == 0)
                rear = max - 1;
            else
                rear--;
        }
    }
};

