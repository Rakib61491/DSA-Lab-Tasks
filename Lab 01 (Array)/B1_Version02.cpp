#include <iostream>
using namespace std;
#define MAX 100000

// Made by ChatGPT , as my capacity was exhausted after completing B1_Version01.cpp , which involved heavily twisted and repetitive logic and required repeated, mental power draining error checking.

void inputArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void showArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int insertElement(int arr[], int n, int index, int value) {
    for (int i = n; i > index; i--)
        arr[i] = arr[i - 1];
    arr[index] = value;
    return n + 1;
}

int processDuplicates(int arr[], int n) {
    int freq[MAX] = {0};
    int lastIndex[MAX];

    // Initialize lastIndex
    for (int i = 0; i < MAX; i++)
        lastIndex[i] = -1;

    // First pass: count frequency and track last occurrence
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
        lastIndex[arr[i]] = i;
    }

    // Offset accounts for previous insertions
    int offset = 0;

    // Second pass: insert counts after last occurrence
    for (int i = 0; i < n; i++) {
        if (freq[arr[i]] > 1 && lastIndex[arr[i]] == i) {
            n = insertElement(arr, n, i + 1 + offset, freq[arr[i]]);
            offset++;
        }
    }

    return n;
}

int main() {
    int arr[MAX];
    int n;

    cout << "Number of elements: ";
    cin >> n;

    cout << "Enter array elements: ";
    inputArray(arr, n);

    cout << "Original array: ";
    showArray(arr, n);

    n = processDuplicates(arr, n);

    cout << "Final array: ";
    showArray(arr, n);

    return 0;
}
