#include <iostream>
#include <sstream>
using namespace std;

// Function to convert integer to string using stringstream
string intToString(int value) {
		ostringstream oss;
		oss << value;
		return oss.str();
}

// Function to find binary representation using bitwise operators
string findBinary(long long decimal) {
		if (decimal == 0) {
				return "0";
		}

		string binary = "";
		while (decimal > 0) {
				int lastBit = decimal & 1;
				binary = intToString(lastBit) + binary;
				decimal >>= 1;
		}

		return binary;
}

// Function to find binary representation using recursion
string find(long long decimal) {
		if (decimal == 0) {
				return "";
		} else {
				return find(decimal / 2) + to_string(decimal % 2);
		}
}

int main() {
		long long n;
		cout << "Enter a number: ";
		cin >> n;

		// Output from bitwise operator method
		cout << "Binary (Bitwise): " << findBinary(n) << endl;

		// Output from recursive method
		string recursiveResult = find(n);
		cout << "Binary (Recursive): " << (recursiveResult.empty() ? "0" : recursiveResult) << endl;

		return 0;
}
