#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left<n && arr[left]>arr[largest]){
        largest = left;
    }

    if(right<n && arr[right]>arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapifyMin(int arr[], int n, int i){
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] < arr[smallest]){
        smallest = left;
    }

    if(right < n && arr[right] < arr[smallest]){
        smallest = right;
    }

    if(smallest != i){
        swap(arr[i], arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

void buildHeap(int arr[], int n){
    for(int i=n/2 - 1; i>=0; i--)
        heapify(arr, n, i);
}

void heaptoArray(int arr[], int n){
    for(int i=n-1; i>0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void insertHeap(int arr[], int &n, int value){
    n++;
    arr[n-1] = value;

    int i = n - 1;

    while(i > 0){
        int parent = (i - 1) / 2;

        if(arr[parent] < arr[i]){
            swap(arr[parent], arr[i]);
            i = parent;
        } else {
            break;
        }
    }
}

void deleteIndex(int arr[], int &n, int index){
    if(index >= n) return;

    arr[index] = arr[n - 1];
    n--;

    int parent = (index - 1) / 2;

    if(index > 0 && arr[index] > arr[parent]){
        while(index > 0){
            parent = (index - 1) / 2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            } else break;
        }
    } else {
        heapify(arr, n, index);
    }
}


int main(){
    int arr[] = {10, 3, 5, 30, 2, 8};
    int n=6;


    cout << "Original Array : ";
    printArray(arr, n);

    buildHeap(arr, n);
    cout << "\nAfter building max Heap : ";
    printArray(arr, n);

    insertHeap(arr, n, 10);
    insertHeap(arr, n, 20);
    insertHeap(arr, n, 5);
    insertHeap(arr, n, 30);
    insertHeap(arr, n, 15);

    cout << "Heap after insertions: ";
    printArray(arr, n);

    deleteIndex(arr, n, 0); 

    cout << "After deleting root: ";
    printArray(arr, n);

    deleteIndex(arr, n, 2); // delete index 2

    cout << "After deleting index 2: ";
    printArray(arr, n);

    

    heaptoArray(arr, n);
    cout << "\nAfter Sorting (Heap Sort) : ";
    printArray(arr, n);


    return 0;
}