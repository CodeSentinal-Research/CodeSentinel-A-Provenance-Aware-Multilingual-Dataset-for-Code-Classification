Here is the required C++ code:

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int total = n+1;
    int totalSum = n*(n+1)/2;

    int ownSum = 0;
    int ownProduct = 1;

    for (int i = 0; i < n; i++) {
        ownSum += arr[i];
        ownProduct *= arr[i];
    }

    int missing = totalSum - ownSum;
    int repeating = totalProduct - ownProduct;

    cout << "Missing number: " << missing << endl;
    cout << "Repeating number: " << repeating << endl;

    return 0;
}

This code reads an integer N followed by N integers. It calculates the sum of numbers from 1 to N and the product of numbers from 1 to N. It then calculates the missing and repeating numbers by subtracting the sum from the total sum and product from the total product, respectively.