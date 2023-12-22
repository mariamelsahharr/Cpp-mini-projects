#include <iostream>
using namespace std;

// Function to perform selection sort on a fixed-size array
void selectionSortSmallest() {
    int min_idx, temp;
    int n = 6;
    int arr[] = {8, 9, 6, 1, 2, 4};

    // Print initial array
    for (int m = 0; m < n; m++) {
        cout << arr[m] << " ";
    }
    cout << endl;

    // Selection sort algorithm
    for (int i = 0; i < n - 1; i++) {
        min_idx = i; // Assume the first element is the minimum
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j; // Update the index of the minimum element
            }
        }

        // Swap the found minimum element with the first element
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;

        // Print the array after each swap
        for (int m = 0; m < n; m++) {
            cout << arr[m] << " ";
        }
        cout << endl;
    }
}

// Function to select and sort the largest k elements in an array
void selectSort(int arr[], int n, int k) {
    int pos_max, temp;
    for (int i = k - 1; i > -1; i--) {
        pos_max = 0; // Assume first element is the largest in unsorted part
        for (int j = 1; j <= n - k + i; j++) {
            if (arr[j] > arr[pos_max]) {
                pos_max = j; // Update the position of the largest element
            }
        }

        // Swap the largest element found with the element at the end of unsorted portion
        temp = arr[n - k + i];
        arr[n - k + i] = arr[pos_max];
        arr[pos_max] = temp;

        // Print the array after each swap
        for (int m = 0; m < n; m++) {
            cout << arr[m] << " ";
        }
        cout << endl;
    }
}

// Main function
int main() {
    // Reading the size of the array and the number of elements to sort
    int n, k;
    cin >> n >> k;
    
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "P4" << endl;
    selectionSortSmallest();

    cout << "P5" << endl;
    selectSort(arr, n, k);

    delete[] arr; // Freeing dynamically allocated memory
    return 0;
}
