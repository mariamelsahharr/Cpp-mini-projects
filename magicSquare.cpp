#include <iostream>
#include <cstring>  // For memset
using namespace std;

// Function to generate a magic square
void generateSquare(int n, int sum) {

     if (n < 3) {
        cout << "Magic Square is not possible for n < 3." << endl;
        return;
    }

    int** magicSquare = new int*[n];
    for (int i = 0; i < n; i++) {
        magicSquare[i] = new int[n];
        memset(magicSquare[i], 0, n * sizeof(int));
    }

    // Start position for the 1st number
    int i = n / 2;
    int j = n - 1;

    // Calculate the adjustment factor x to meet the desired sum
    int x = (sum / n) - (((n * n) - 1) / 2);
    cout << "The value of x is " << x << endl;

    // One by one put all values in the magic square
    for (int num = x; num <= ((n * n) + x);) {
        // Check the bounds of the square and adjust the position
        if (i == -1 && j == n) {
            j = n - 2;
            i = 0;
        } else {
            if (j == n) j = 0;
            if (i < 0) i = n - 1;
        }

        // Place the number and adjust if the cell is already filled
        if (magicSquare[i][j]) {
            j -= 2;
            i++;
            continue;
        } else {
            magicSquare[i][j] = num++;
        }

        // Move to the next cell
        j++;
        i--;
    }

    // Print the magic square
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << magicSquare[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] magicSquare[i];
    }
    delete[] magicSquare;
    
}

int main() {
    int n, desiredSum;
    cout<<"Enter the size of the magic square, and the desired sum: "<<endl;
    cin >> n >> desiredSum;
    generateSquare(n, desiredSum);
    return 0;
}