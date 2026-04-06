// You need to build Navigation History system. Use a Doubly Linked List. You must process a stream of user commands :
// - VISIT <url> → loads the new page, adding it immediately after the current page. Delete all forward history after it.
// - FORWARD → Moves the active view to the next page in the history.
// - Back → Moves the active view to the previous page.
// After all commands are done, show:
// - The output sequence of retained history from the oldest to newest.
// - The url of Active view the current page is showing.

#include<iostream>
#include<string>
using namespace std;


class Page{
public:
    string url;
    Page* prev;
    Page* next;
    Page(string url){
        this->url = url;
        prev = next = NULL;
    }
};

class Nav_History{
    Page* head;
    Page* curr;
public:
    Nav_History(){
        head = curr = NULL;
    }

    void forward(){
        if(head==NULL){
            cout << "No url is active\n";
            return;
        }
        if(curr->next!=NULL)
            curr = curr->next;
        return;
    }
    
    void back(){
        if(head==NULL){
            cout << "No url is active\n";
            return;
        }
        if(curr->prev!=NULL)
            curr = curr->prev;
        return;
    }

    void add(string url){
        Page* newNode = new Page(url);
        if(head==NULL){
            head = curr = newNode;
            return;
        }
        Page* temp = curr->next;    // Needed to be deallocated after ADD
        curr->next = newNode;
        newNode->prev = curr;
        curr = curr->next;
        while(temp!=NULL){    // Deallocate all history after the current 
            Page* temp2 = temp;
            temp = temp->next;
            delete temp2;
        }
    }

    void show(){
        if(head==NULL){
            cout << "No url is Active\n";
            return;
        }
        Page* temp = head;
        cout << "History : ";
        while(temp!=NULL){
            cout << temp->url;
            if(temp->next!=NULL)  cout << ", ";
            temp = temp->next;
        }
        cout << endl << "Active View : " << curr->url << endl;
        return;
    }
};


int main(){
    Nav_History h1;
    string command;
    while(true){
        cin >> command;
        if(command=="SHOW")
            h1.show();
        else if(command=="FORWARD"){
            h1.forward();
            // h1.show();
        }
        else if(command=="BACK"){
            h1.back();
            // h1.show();
        }
        else if(command=="VISIT"){
            string url;
            cin >> url;
            h1.add(url);
            // h1.show();
        }
        else{
            cout << "Please type again\n";
        }
    }
}