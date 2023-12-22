#include <iostream>
#include <cstring>
using namespace std;

// Function to implement the Sieve of Eratosthenes
void sieveOfEratosthenes(int n) {
    // Create a boolean array "prime[0..n]" and initialize all entries as true.
    // A value in prime[i] will finally be false if i is Not a prime, else true.
    bool* prime = new bool[n + 1];
    memset(prime, true, sizeof(bool) * (n + 1));

    // Loop to mark the multiples of primes as false
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            cout << p << " ";
        }
    }

    // Deallocate memory
    delete[] prime;
}

// Main function
int main() {
    int n;
    cin >> n;
    sieveOfEratosthenes(n);
    return 0;
}
