#include<iostream>
#include<string>
using namespace std;

void getArray(int arr[], int size){
    for(int i=0; i<size; i++)
        cin >> arr[i];
}

void showArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sortArray(int arr[], int size){
    // Bubble Sort 
    for(int i=0; i<size-1; i++){
        for(int j=i; j<size; j++){
            if(arr[j]<arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int searchArray(int arr[], int size, int value){
    for(int i=0; i<size; i++){
        if(arr[i] == value)
            return i;
    }
    return -1;
}

int insertArray(int arr[], int size, int index, int value){
    if(index<0 || index>size){
        return size;
    }
    for(int i=size; i>index; i--){
        arr[i] = arr[i-1];
    }
    arr[index] = value;
    return size+1;
}

int deletebyvalue(int arr[], int size, int value){
    int idx = searchArray(arr, size, value);
    if(idx!=-1){
        for(int i=idx; i<size-1; i++){
            arr[i] = arr[i+1];
        }
        return size-1;
    }
    else{
        return -1;
    }
}

int main(){
    int n;
    cout << "Number of element : ";
    cin >> n;
    int arr[100];
    cout << "Enter elements for array : ";
    getArray(arr, n);
    
    sortArray(arr, n);
    cout << "The Sorted array is : ";
    showArray(arr, n);

    int key, val;
    cout << "What Value do you want to insert : ";
    cin >> val;
    cout << "In What index do you want to insert : ";
    cin >> key;
    key--;
    n = insertArray(arr, n, key, val);
    showArray(arr, n);

    int value_search;
    cout << "The index of the Element you want to Search : ";
    cin >> value_search;
    int searched_index = searchArray(arr, n, value_search);
    if(searched_index!=-1){
        cout << "The index is : " << searched_index << endl;
    }
    else{
        cout << "Not Found !" << endl;
    }

    int value_del;
    cout << "What value do you want to delete ? : ";
    cin >>value_del;
    n = deletebyvalue(arr, n, value_del);
    showArray(arr, n);


    cout << "The Modified array is : ";
    showArray(arr, n);


    return 0;    
}