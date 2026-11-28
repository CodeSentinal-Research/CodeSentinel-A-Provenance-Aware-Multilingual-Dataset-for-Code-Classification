Here is the C++ code for the problem:

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of congruences: ";
    cin >> n;

    int congruences[n];
    cout << "Enter the congruences: ";
    for (int i = 0; i < n; i++) {
        cin >> congruences[i];
    }

    int earliestTimestamp = 0;
    for (int i = 0; i < n; i++) {
        earliestTimestamp = (earliestTimestamp + congruences[i]) % congruences[i];
    }

    cout << "Earliest Timestamp: " << earliestTimestamp << endl;

    return 0;
}

This code first reads the number of congruences from the user. Then it reads the congruences themselves. For each congruence, it calculates the earliest timestamp by summing up the congruences and taking the modulus with the next congruence. The result is the earliest timestamp satisfying all the given conditions.