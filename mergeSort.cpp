#include <iostream>
#include <string>
#include <vector>
using namespace std;

int x = 0; // Global variable to track the number of recursive calls to mergeSort

// Merge two subarrays L and M into arr
void merge(vector<string>& arr, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    vector<string> L(n1), M(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i = 0, j = 0, k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(vector<string>& arr, int l, int r) {
    x++;  // Incrementing the global variable for each call
    
    if (l < r) {
        // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted subarrays
        merge(arr, l, m, r);
    }
}

// Print the array
void printArray(const vector<string>& arr) {
    for (const string& element : arr)
        cout << element << " ";
    cout << endl;
}

// Driver program
int main() {
    int num;
    cout << "Enter the number of elements: ";
    cin >> num;

    vector<string> a(num);  // Using vector for dynamic array

    cout << "Enter the elements (strings): ";
    for (string& element : a)
        cin >> element;

    mergeSort(a, 0, num - 1);

    cout << "Number of mergeSort calls: " << x << endl;

    printArray(a);

    return 0;
}
