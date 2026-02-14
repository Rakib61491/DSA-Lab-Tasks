// Question : Remove Duplicates from the Array 
#include<iostream>
using namespace std;
#define MAX 100000

// To beter visualization of how deletion is working in each iteration, please uncomment those comments  

void inputArray(int arr[], int size){
    for(int i=0; i<size; i++)
        cin >> arr[i];
}

void showArray(int arr[], int size){
    for(int i=0; i<size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int deleteElement(int arr[], int size, int index){
    if(index<0 || index>=size)
        return size;

    for(int i=index; i<size; i++)
        arr[i] = arr[i+1];
    return --size;
}

int deleteDuplicates(int arr[], int size){
    for(int i=0; i<size-1; i++){
        // cout << endl << "The iteration : " << i << " for element : " << arr[i] << endl;
        for(int j=i+1; j<size; j++){
            // cout << j << " , element : " << arr[j];
            if(arr[i] == arr[j]){
                size = deleteElement(arr, size, j);
                j--;
                // cout << " Duplicate Detected; Size : " << size << " , j = " << j;
            }
            // cout << endl;
        }
        // showArray(arr, size);
    }
    return size;
}

int main()
{
    int array[MAX];
    int n;
    cout << "Number of Element : ";
    cin >> n;
    cout << "Please Enter the elements of Array : ";
    inputArray(array, n);
    // showArray(array, n);
    // cout << "Here is the duplicates deletion : ";
    n = deleteDuplicates(array, n);
    cout << endl << "After deleting duplicates, the Array : ";
    showArray(array, n);
}