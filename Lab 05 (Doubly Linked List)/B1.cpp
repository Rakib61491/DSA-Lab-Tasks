// You need to build Navigation for PHOTO GALLERY APPLICATION. Use a Doubly Linked List. You must process a stream of user commands :
// - NEXT → Moves the viewing pic to the next pic.
// - PREV → Moves the viewing pic to the previous pic
// - REMOVE → Delete the viewing picture and moves to the next picture. If no next ric remains, goes to previous pic.
// After all commands are done, show:
// - The output sequence of retained history from the oldest to newest.
// - The url of Active view the current page is showing.

#include<iostream>
#include<string>
using namespace std;


class Photo{
public:
    string pic;
    Photo* next;
    Photo* prev;
    Photo(string pic){
        this->pic = pic;
        prev = next = NULL;
    }
};


class Gallery{
    Photo* head;
    Photo* curr;
public:
    Gallery(){
        head = curr = NULL;
    }

    void add(string pic){
        Photo* newNode = new Photo(pic);
        if(head==NULL){
            head = curr = newNode;
            return;
        }
        Photo* temp = head;
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        curr = newNode;
    }

    void forward(){
        if(head==NULL){
            cout << "No pic remains";
            return;
        }
        if(curr->next!=NULL)
            curr = curr->next;
        return;
    }

    void back(){
        if(head==NULL){
            cout << "No pic remains";
            return;
        }
        if(curr->prev!=NULL)
            curr = curr->prev;
        return;
    }

    void show(){
        if(head==NULL){
            cout << "No pic remains";
            return;
        }
        Photo* temp = head;
        cout << "Remaining Gallery : ";
        while(temp!=NULL){
            cout << temp->pic;
            if(temp->next!=NULL)  cout << ", ";
            temp = temp->next;
        }
        cout << endl << "Currently Viewing : " << curr->pic << endl;
    }

    void remove(){
        if(head==NULL || head->next==NULL){
            head=curr=NULL;
            return;
        }
        if(curr==head){
            head= head->next;
            delete curr;
            curr = head;
            return;
        }
        curr->prev->next = curr->next;
        if(curr->next!=NULL)
            curr->next->prev = curr->prev;

        Photo* temp = curr;
        if(curr->next!=NULL)
            curr =curr->next;
        else
            curr = curr->prev;
        delete temp;
    }
};

int main(){
    Gallery g;
    int n;
    string pics;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> pics;
        g.add(pics);
    }
    string command;
    while(true){
        cin >> command;
        if(command=="SHOW")
            g.show();
        else if(command=="FORWARD"){
            g.forward();
            g.show();
        }
        else if(command=="BACK"){
            g.back();
            g.show();
        }
        else if(command=="REMOVE"){
            g.remove();
            g.show();
        }
        else{
            cout << "Please type again\n";
        }
    }
}