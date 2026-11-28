Here's the C++ code for the problem:

#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> res;
    long long factorial = 1;
    for (int i = 1; i <= rowIndex + 1; i++) {
        res.push_back(factorial = factorial * i);
    }
    return res;
}

int main() {
    int rowIndex;
    cout << "Enter rowIndex: ";
    cin >> rowIndex;
    if (rowIndex < 0 || rowIndex > 33) {
        cout << "Invalid input!";
        return 0;
    }

    vector<int> row = getRow(rowIndex);
    cout << "The corresponding row is: ";
    for (int num : row) {
        cout << num << " ";
    }
    return 0;
}

This program will first prompt the user for a rowIndex. If the rowIndex is invalid (i.e., less than 0 or greater than 33), it will print an error message and terminate.

If the rowIndex is valid, it will calculate the row using Pascal's Triangle formula (n choose k) = n! / (k!(n-k)!), where n is the rowIndex and k is the columnIndex. The result is then printed out.