// Question : print the first and last occurrence of the elements  of an array
// Input: 5,4,5,2,4,3,2,2,5 output: 5,4,2,4,3,2,5

#include<iostream>
using namespace std;
#define MAX 100000  

void inputArray(int arr[], int size){
    for(int i=0; i<size; i++)
        cin >> arr[i];
}

void showArray(int arr[], int size){
    for(int i=0; i<size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int insertElement(int arr[], int size, int index, int element){
    if(index<0 || index>size)
        return size;

    for(int i=size; i>index; i--)
        arr[i] = arr[i-1];
    arr[index] = element;
    return ++size;
}

int deleteElement(int arr[], int size, int index){
    if(index<0 || index>=size)
        return size;

    for(int i=index; i<size; i++)
        arr[i] = arr[i+1];
    return --size;
}

int modifyDuplicates(int arr[], int size){
    for(int i=0; i<size; i++){
        int res = -1;
        for(int j=i+1; j<size; j++){
            if(arr[i] == arr[j]){
                size = deleteElement(arr, size, j);
                res = j;
                j--;
            }
        }
        size = insertElement(arr, size, res, arr[i]);
    }
}

int main()
{
    int array[MAX];
    int n;
    cout << "Number of Element : ";
    cin >> n;
    cout << "Please Enter the elements of Array : ";
    inputArray(array, n);
    showArray(array, n);

    cout << endl << "After modifying : \n";
    n = modifyDuplicates(array, n);
    showArray(array, n);
}