#include<bits/stdc++.h>
using namespace std;

int main(){
    list<int> l;
    int n;
    // cout << l.size() << " " << l.empty() << endl; 
    // l.push_back(5);
    // l.push_back(6);
    // l.push_back(8);
    // l.push_back(11);
    // cout << l.size() << " " << l.empty() << endl; 

    cin >> n;
    for(int i = 0; i<n; i++){
        int a;
        cin >> a;
        l.push_back(a); 
    }

    cout << "List : ";
    for(int i:l){
        cout << i << " ";
    } cout << endl;
    
    for(auto i=l.begin(); i!=l.end(); ){
        if(*i % 2 == 0)
            i = l.erase(i);
        else
            i++;
    }
    cout << "Odd List : ";
    for(int i:l){
        cout << i << " ";
    } cout << endl;

    cout << "Enter Number : ";
    int num;
    cin >> num;

    for(auto i=l.begin(); i!=l.end(); ){
        if(*i == num){
            if(i != l.begin()){
                auto prv = prev(i);
                i = l.erase(prv);
            }
            auto nxt = next(i);
            l.insert(nxt, 12);
            break;
        }
        i++;
    }
    
    
    cout << "Modified List : ";
    for(int i:l){
        cout << i << " ";
    }
}