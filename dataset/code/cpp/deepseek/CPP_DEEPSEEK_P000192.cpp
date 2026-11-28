Here is a C++ solution for the problem:

#include <iostream>
using namespace std;

void moveNegatives(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            count++;
        }
    }

    int newArr[n-count];

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            newArr[j++] = arr[i];
        }
    }

    for (int i = 0; i < count; i++) {
        newArr[j++] = arr[i];
    }

    for (int i = 0; i < n-count; i++) {
        cout << newArr[i] << " ";
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    moveNegatives(arr, n);

    return 0;
}

This code reads an integer `n` (the number of elements in the array), and then reads `n` integers into an array. It then calls the `moveNegatives` function to move all negative elements to the left side of the array.