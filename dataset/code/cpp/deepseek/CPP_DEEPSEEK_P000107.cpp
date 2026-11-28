Here is the C++ code that checks if an array is sorted in ascending order.

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    bool isSorted = true;
    for(int i = 0; i < n - 1; i++) {
        if(arr[i] > arr[i+1]) {
            isSorted = false;
            break;
        }
    }
    if(isSorted) {
        cout << "Sorted" << endl;
    } else {
        cout << "Not Sorted" << endl;
    }
    return 0;
}

This program first reads the size of the array from the standard input. It then reads the array elements from the standard input. The program then iterates over the array. If it finds two elements that are out of order (i.e., the first element is greater than the second), it sets `isSorted` to `false` and breaks the loop. If it does not find any out-of-order pairs, it prints "Sorted".