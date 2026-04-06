// Write a menu driven program to implement Singly Linked List. The program must repeatedly display a menu and some selected operation
// 1. Display : Print all elements of the linked list in order 
// 2. Insert at first : Insert a new value at the start of the list 
// 3. Conditional Delete operation : Delete every odd elements
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

    void insertAtFirst(int data){
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return;
    }

    void deleteConditional(){
        if(head==NULL){
            cout << "List Empty\n";
            return;
        }
        Node* temp1 = head;
        Node* temp2 = NULL;
        while(temp1!=NULL){
            if(temp1->data%2 != 0){
                if(temp2==NULL){    // temp1 being head(odd) and temp2 NULL [Condition]
                    head = temp1->next;
                    delete temp1;
                    temp1 = head;    // temp1(head) being deleted, next Node becomes head(temp1)
                }
                else{    // Main logic of odd number Node deletion
                    temp2->next = temp1->next;
                    delete temp1;
                    temp1 = temp2->next;
                }
            }
            else{    // Traversal until temp1->next being NULL
                temp2 = temp1;
                temp1 = temp1->next;
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
    cout << "1. Display\n2. Insert at First\n3. Conditional Delete\n4. Exit\n";
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
            ll.insertAtFirst(ele);
            cout << endl;
        }
        else if(option==3){
            ll.deleteConditional();
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