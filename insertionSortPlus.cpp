#include <iostream>
using namespace std;

// Function to perform insertion sort on an integer array
void insertion_sortP1(int arr[], int length) {
    cout << "P1" << endl;
    // Start from the second element (index 1)
    for (int i = 1; i < length; i++) {
        int current = i;
        // Move elements greater than arr[current] one position ahead
        // to create space for inserting arr[current] in sorted part
        while (current > 0 && arr[current] < arr[current - 1]) {
            swap(arr[current], arr[current - 1]);
            current--;
        }

        // Print the array after each insertion
        for (int m = 0; m < length; m++) {
            cout << arr[m] << " ";
        }
        cout << endl;
    }
}

// Function to sort an array of strings using insertion sort
void p3() {
    // Array of planet names
    string arnList[9] = {"mercury", "venus", "earth", "mars", "jupiter", "saturn", "uranus", "neptune"};
    int nLength = 9;
    cout << "P3" << endl;

    // Insertion sort algorithm for strings
    for (int i = 1; i < nLength; i++) {
        string temp = arnList[i];
        int k = i - 1;
        while (k >= 0 && arnList[k] > temp) {
            arnList[k + 1] = arnList[k];
            k--;
        }
        arnList[k + 1] = temp;

        // Print the array after each insertion
        for (int m = 0; m < nLength; m++) {
            cout << arnList[m] << " ";
        }
        cout << endl;
    }
}

// Function to sort an array of doubles and find the median
double p4(double arr[], int length) {
    cout << "P4" << endl;
    // Insertion sort for the array of doubles
    for (int i = 1; i < length; i++) {
        int current = i;
        while (current > 0 && arr[current] < arr[current - 1]) {
            swap(arr[current], arr[current - 1]);
            current--;
        }
    }

    // Calculate and return the median
    double median;
    if (length % 2 != 0) {
        median = arr[length / 2];
    } else {
        median = (arr[(length / 2) - 1] + arr[length / 2]) / 2;
    }
    return median;
}

// Main function
int main() {
    // Read number of elements for P4
    cout << "Enter the number of elements for P4: ";
    int n;
    cin >> n;

    // Dynamic array for P4
    double* arr4 = new double[n];
    cout << "Enter " << n << " elements for P4: ";
    for (int i = 0; i < n; i++) {
        cin >> arr4[i];
    }

    // Array for P1
    int p1Arr[7] = {6, 2, 8, 3, 1, 7, 4};
    insertion_sortP1(p1Arr, 7); // Sort and print steps of insertion sort
    p3(); // Sort and print steps of insertion sort for string array
    cout << "Median (P4): " << p4(arr4, n) << endl; // Sort array and find median

    delete[] arr4; // Free dynamically allocated memory

    return 0;
}
