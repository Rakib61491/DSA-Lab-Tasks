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

int deleteElement(int arr[], int size, int index){
    if(index<0 || index>=size)
        return size;

    for(int i=index; i<size; i++)
        arr[i] = arr[i+1];
    return --size;
}

int countsDuplicates(int arr[], int size){
    int total_duplicates=0;
    int cnt=0;
    for(int i=0; i<size-1; i++){
        for(int j=i+1; j<size; j++){
            if(arr[i] == arr[j]){
                size = deleteElement(arr, size, j);
                cnt++;
                total_duplicates++;
                j--;
            }
        }
        cout << "The element " << arr[i] << " is duplicated : " << cnt << " times \n"; 
        cnt = 0;
    }
    return total_duplicates;
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

    int t = countsDuplicates(array, n);
    cout << endl << "Total Duplicates : " << t << endl;
}