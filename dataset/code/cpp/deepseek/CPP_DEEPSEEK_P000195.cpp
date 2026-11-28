Here is the C++ code for the cyclically rotating array by one position to the right:

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    int last = arr[n-1];
    for(int i=n-1; i>0; i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = last;
    
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

This code first reads the size of the array from the standard input. Then it reads the elements of the array. After that, it uses a simple algorithm to cyclically shift the array by one position to the right. Finally, it outputs the rotated array.