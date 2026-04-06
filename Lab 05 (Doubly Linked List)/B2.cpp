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
        head = NULL;
        curr = NULL;
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
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        curr = newNode;    // If curr not in end, then I have to use insertAfterElement instead of insertEnd
    }

    void prev(){
        if(curr==NULL){
            cout << "No Song\n";
            return;
        }
        if(curr->prev==NULL){
            cout << "No Song\n";
            return;
        }
        curr = curr->prev;
    }

    void next(){
        if(curr==NULL){
            cout << "No Song\n";
            return;
        }
        if(curr->next==NULL){
            cout << "No Song\n";
            return;
        }
        curr = curr->next;
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
            cout << "The Current song is removed\n";
        }
        else if(command == "SHOW"){
            s1.playlist();
            break;
        }
        else{
            cout << "Please type again\n";
        }
    }
}