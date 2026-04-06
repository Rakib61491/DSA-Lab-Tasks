// Write a menu driven program to implement Singly Linked List. The program must repeatedly display a menu and some selected operation
// 1. Display : Print all elements of the linked list in order 
// 2. Insert at last : Insert a new value at last of the list 
// 3. Conditional Insert operation : Insert value 200 after every odd elements
// 4. Exit

#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(){
        data = 0;
        next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList{
    Node* head;
public:
    LinkedList(){head = NULL;}

    void insertAtLast(int data){
        Node* newNode = new Node(data);
        if(head==NULL){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next = newNode;
        return;
    }

    void insertConditional(){
        if(head==NULL){
            cout << "List Empty\n";
            return;
        }
        Node* temp = head;
        while(temp!=NULL){
            if(temp->data%2 != 0){
                Node* newNode = new Node(200);
                newNode->next = temp->next;
                temp->next = newNode;
                temp = newNode->next;
            }
            else{
                temp = temp->next;
            }
        }        
        cout << "Done ...\n";
        return;
    }

    void display(){
        if(head==NULL){
            cout << "No element in the list\n";
            return;
        }
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        return;
    }
};


int main(){
    LinkedList ll;
    cout << "==================================== MENU ====================================\n";
    cout << "1. Display\n2. Insert at Last\n3. Conditional Insert\n4. Exit\n";
    while(true){
        int option;
        cout << "Please choose your option : ";
        cin >> option;
        if(option==1){
            ll.display();
            cout << endl;
        }
        else if(option==2){
            int ele;
            cout << "Enter the element you want to add : ";
            cin >> ele;
            ll.insertAtLast(ele);
            cout << endl;
        }
        else if(option==3){
            ll.insertConditional();
            cout << endl;
        }
        else if(option==4){
            cout << endl;
            break;
        }
        else{
            cout << "You have clicked a wrong option. Please try again ....\n";
            cout << endl;
        }
    }

    cout << "Program is terminated\n";
}