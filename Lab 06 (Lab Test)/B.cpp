// Create a hospital management system. It has two rooms : Waiting Room and Treatment Ward. Here are the functions for the system :
// 1. WALK_IN : The id of patient is added in waiting room at the back.
// 2. AMBULANCE : The id of patient is added in waiting room at the front.
// 3. ADMIT : The first patient(ID) is deleted from waiting room and admitted into treatment ward at last
// 4. DISCHARGE : Matches the id given with it with patient's id in treatment ward. If found, the patient is deleted.
// 5. REVERSE_ORDER : Show the list of patients id in treatment ward in reverse order.

#include<iostream>
#include<string>
using namespace std;
#define MAX 10000

int addLast(int arr[], int size, int data){
    arr[size] = data;
    return ++size;
}

int addFirst(int arr[], int size, int data){
    for(int i=size; i>0; i--)
        arr[i] = arr[i-1];
    arr[0] = data;
    return ++size;
}

int delarr(int arr[], int size, int idx){
    for(int i=idx; i<size; i++)
        arr[i] = arr[i+1];
    return --size;
}

void show(int arr[], int size){
    if(size==0){
        cout << "No Patient is admitted\n";
        return;
    }
    for(int i=0; i<size; i++)
        cout << "Patient " << arr[i] << " ";
    cout << endl;
}

int main(){
    int wr[MAX], tw[MAX];    //wr --> Waiting room, tw --> Treatment ward
    int n1 = 0, n2 = 0;    // n1 and n2 represents the number of patients in Waiting room and Treatment ward in order
    string command;
    while(true){
        cin >> command;
        if(command=="WALK_IN"){    
            int id;
            cin >> id;
            n1 = addLast(wr, n1, id);
            cout << "Waiting Room : ";
            show(wr, n1);
        }
        else if(command=="AMBULANCE"){    
            int id;
            cin >> id;
            n1 = addFirst(wr, n1, id);
            cout << "Waiting Room : ";
            show(wr, n1);
        }
        else if(command=="ADMIT"){    
            int id = wr[0];
            n1 = delarr(wr, n1, 0);
            n2 = addLast(tw, n2, id);
            cout << "Treatment Ward : ";
            show(tw, n2);
        }
        else if(command=="DISCHARGE"){     
            int id, res=-1;
            cin >> id;
            for(int i=0; i<n2; i++){
                if(tw[i]==id)
                    res = i;
            }
            cout << res << endl;
            if(res!=-1)
                n2 = delarr(tw, n2, res);
            else    
                cout << "Patient is not found\n";
            cout << "Treatment Ward : ";
            show(tw, n2);
        }
        else if(command=="REVERSE_ORDER"){    
            int tw_reverse[MAX];
            for(int i=0; i<n2; i++)
                tw_reverse[i] = tw[n2-i-1];
            cout << "Treatment Ward : ";
            show(tw_reverse, n2);
        }
    }

}
