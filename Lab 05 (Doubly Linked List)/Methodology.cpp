#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val){
        data = val;
        prev = next = NULL;
    }
};

class DoublyLinkedList{
    Node* head;
public:
    DoublyLinkedList(){
        head = NULL;
    }

    void display(){
        if(head==NULL){
            cout << "No element\n";
            return;
        }
        Node* temp = head;
        cout << "Display : ";
        while(temp!=NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        return;
    }
    
    void insertAtBeginning(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head = newNode;
            return;
        }
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    
    void insertAtLast(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    
    void insertAfter(int target, int val){
        if(head==NULL){
            cout << "No element\n";
            return;
        }
        Node* temp = head;
        while(temp!=NULL && temp->data!=target){
            temp = temp->next;
        }
        if(temp==NULL){    // Target not in list
            cout << "Target value not Found\n";
            return;
        }
        if(temp->next==NULL){    // Target at the End of the list
            insertAtLast(val);
            return;
        }
        Node* newNode = new Node(val);

        newNode->next = temp->next;
        temp->next->prev = newNode;
        newNode->prev = temp;
        temp->next = newNode;
        return;
    }

    void insertBefore(int target, int val){
        if(head==NULL){
            cout << "No element\n";
            return;
        }
        Node* temp = head;
        while(temp!=NULL && temp->data!=target){
            temp = temp->next;
        }
        if(temp==NULL){    // Target not in list
            cout << "Target value Not Found\n";
            return;
        }
        if(temp==head){    // Target is Head
            insertAtBeginning(val);
            return;
        }
        Node* newNode = new Node(val);

        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        newNode->next = temp;
        temp->prev = newNode;
    }

    void deleteFirst(){
        if(head==NULL){    // 0 element 
            return;
        }
        if(head->next==NULL){    // 1 element --> 0 element
            delete head;
            head=NULL;
            return;
        }
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    }

    void deleteLast(){
        if(head==NULL){    // 0 element
            return;
        }
        if(head->next==NULL){    // 1 element --> 0 element
            delete head;
            head=NULL;
            return;
        }
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;
    }

    void deleteElement(int target){
        if(head==NULL){    // 0 element
            return;
        }
        Node* temp = head;
        while(temp!=NULL && temp->data!=target){
            temp = temp->next;
        }
        if(temp==NULL){
            cout << "Target value Not Found\n";
            return;
        }
        if(temp==head){    // Targt --> Head : Delete First Element
            deleteFirst();
            return;
        }
        if(temp->next==NULL){    // Targt --> Last element : Delete Last Element
            deleteLast();
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    void deleteBefore(int target){
        if(head==NULL){    // 0 element
            return;
        }
        Node* temp = head;
        while(temp!=NULL && temp->data!=target){
            temp = temp->next;
        }
        if(temp==NULL){
            cout << "Target value Not Found\n";
            return;
        }
        if(temp==head){
            cout << "No element before " << target << " element in the list\n";
            return;
        }
        deleteElement(temp->prev->data);
    }

    void deleteAfter(int target){
        if(head==NULL){    // 0 element
            return;
        }
        Node* temp = head;
        while(temp!=NULL && temp->data!=target){
            temp = temp->next;
        }
        if(temp==NULL){
            cout << "Target value Not Found\n";
            return;
        }
        if(temp->next==NULL){
            cout << "No element after " << target << " element in the list\n";
            return;
        }
        deleteElement(temp->next->data);
    }
};
