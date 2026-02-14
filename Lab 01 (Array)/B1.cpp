// Question : Given an array of integers, identify all elements that appear more than once.
// For each such eleemet, insert the total count of that element immediately after its last occurrence.
// Example : Input : arr = [4, 2, 4, 3, 2, 2, 5]
// Output : arr = [4, 2, 4, 2, 3, 2, 2, 3, 5]

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

void copyArray(int arr[], int size, int arr2[]){
    for(int i=0; i<size; i++)
        arr2[i] = arr[i];
}

int deleteElement(int arr[], int size, int index){
    if(index<0 || index>=size)
        return size;

    for(int i=index; i<size; i++)
        arr[i] = arr[i+1];
    return --size;
}

int insertElement(int arr[], int size, int index, int element){
    if(index<0 || index>size)
        return size;

    for(int i=size; i>index; i--)
        arr[i] = arr[i-1];
    arr[index] = element;
    return ++size;
}

int countsDuplicates(int arr[], int size, int arr2[], int size2){
    int total_duplicates=0, flag=0;
    for(int i=0; i<size; i++){
        cout << endl << "The iteration : " << i << " for element : " << arr[i] << endl;
        int cnt=1, idx=-1;
        for(int j=i+1; j<size; j++){
            if(arr[i] == arr[j]){
                size = deleteElement(arr, size, j);
                cnt++;
                total_duplicates++;
                idx=j;
                j--;
            }
        }
        if(cnt>1){
            cout << "The element " << arr[i] << " , Count : " << cnt << " times , Total_Duplicates : " << total_duplicates << " and last Index : " << idx << endl;
            size2 = insertElement(arr2, size2, idx+total_duplicates+flag, cnt);
            flag++;
            showArray(arr2, size2);
        }
    }

    return size2;
}

int main()
{
    int array[MAX];
    int n;
    cout << "Number of Element : ";
    cin >> n;
    cout << "Please Enter the elements of Array : ";
    inputArray(array, n);
    cout << "Array 1 : ";
    showArray(array, n);
    
    int array2[MAX];
    copyArray(array, n, array2);
    cout << "Array 2 : ";
    showArray(array2, n);

    cout << "After changes : ";
    int p = countsDuplicates(array, n, array2, n);
    showArray(array2, p);
}