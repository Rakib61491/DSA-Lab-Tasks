 #include<iostream>
using namespace std;

// template<class T>
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

    void insertNodeAtLast(int data){
        Node* newNode = new Node(data);
        if(head==NULL){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    void insertAtFront(int data){
        Node* newNode = new Node(data);
        if(head==NULL){
            head = newNode;
            return;
        }
        Node* temp = head;
        head = newNode;
        head->next = temp;
        return;
    }

    void insertAtMiddle(int data, int pos){
        Node* newNode = new Node(data);
        if(head==NULL){
            head = newNode;
            return;
        }
        Node* temp = head;
        if(pos==0){
            insertAtFront(data);
            return;
        }
        for(int i=0; i<pos-1; i++){
            if(temp->next==NULL){
                cout << "Invalid Position\n";
                return;
            }
            temp = temp->next;
        }
        Node* temp2 = temp->next;
        temp->next = newNode;
        newNode->next = temp2;
    }

    void printList(){
        Node* temp = head;
        if(temp==NULL){
            cout << "List is Empty\n";
            return;
        }
        while(temp!=NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void deleteNode(int offsetNode){
        if(head==NULL){
            cout << "List Empty\n";
            return;
        }
        int listLen = 0;
        Node* temp = head;
        while(temp!=NULL){
            listLen+=1;
            temp = temp->next;
        }
        delete temp;
        
        if(offsetNode>listLen || offsetNode<=0){
            cout << "Index out of the Range\n";
            return;
        }

        if(offsetNode==1){
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp1 = head;
        Node* temp2 = NULL;

        while(offsetNode-->1){
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next = temp1->next;
        delete temp1;        
    }
};


int main(){
    LinkedList list;
    list.printList();

    list.insertNodeAtLast(5);
    list.printList();
    
    list.insertNodeAtLast(10);
    list.printList();

    list.insertNodeAtLast(15);
    list.printList();

    list.insertNodeAtLast(20);
    list.printList();
    
    list.insertAtFront(50);
    list.printList();
    
    list.insertAtMiddle(100, 2);
    list.printList();

    list.deleteNode(1);
    list.printList();

    list.deleteNode(3);
    list.printList();

    list.deleteNode(7);
    list.printList();
}