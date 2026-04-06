// You need to build a music playlist system. Use a Doubly Linked List.  The playlist starts empty. The system must follow these commands:
// - ADD <song> → Put the new song right after the current song. Start playing this new song. If the list is empty, it becomes the first song.
// - NEXT → Move to the next song.
// - PREV → Move to the previous song.
// - REMOVE → Delete the current song. If there is a next song, play it. If you removed the last song, play the previous one.
// After all commands are done, show:
// - The final playlist order.
// - The song that is currently playing.

#include<iostream>
#include<string>
using namespace std;

class Node{
public:
    string data;
    Node* prev;
    Node* next;

    Node(string val){
        data = val;
        prev = next = NULL;
    }
};

class Song{
    Node* head;
    Node* curr;
public:
    Song(){
        head = NULL; curr = NULL;
    }

    void playlist(){
        if(head==NULL){
            cout << "No Song\n";
            return;
        }
        Node* temp = head;
        cout << "Playlist : ";
        while(temp!=NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\nCurrently Playing : " << curr->data << endl;
        return;
    }

    void add(string val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head = newNode;
            curr = head;
            return;
        }
        Node* temp = head;
        while(temp!=curr){    // Goes to CURR song
            temp = temp->next;
        }
        newNode->next = temp->next;
        if(temp->next!=NULL)    // If Curr is last song, then when constructing new song after curr, there would be no song left (NULL) and NULL doesn't need to have 'prev'.
            temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
        curr = temp->next;
        return;        
    }

    void prev(){
        if(curr==NULL || curr->prev==NULL){
            cout << "No Song\n";
            return;
        }
        curr = curr->prev;
    }

    void next(){
        if(curr==NULL || curr->next==NULL){
            cout << "No Song\n";
            return;
        }
        curr = curr->next;
    }

    void remove(){
        if(curr==NULL){
            cout << "No Song\n";
            return;
        }
        if(curr==head){    // If curr is HEAD
            if(curr->next == NULL){    // If only one song left in playlist
                delete curr;
                head = curr = NULL;
                cout << "No Song\n";
                return;
            }
            head = curr->next;
            delete curr;
            curr = head;
            return;
        }

        Node* temp = curr;
        if(curr->next==NULL){    //If curr is the last element
            curr = curr->prev;
            curr->next = NULL;
        }
        else{    // Else- Curr is in middle and it has next song
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            curr = curr->next;
        }
        delete temp;
        return;

    }
};


int main(){
    Song s1;
    while(true){
        cout << "Type : ";
        string command;
        cin >> command;
        if(command == "ADD"){
            string song;
            cin >> song;
            s1.add(song);
            cout << "The song " << song << " is added\n";
        }
        else if(command == "PREV"){
            s1.prev();
        }
        else if(command == "NEXT"){
            s1.next();
        }
        else if(command == "REMOVE"){
            s1.remove();
        }
        else if(command == "SHOW"){
            s1.playlist();
            // break;
        }
        else{
            cout << "Please type again\n";
        }
    }
}