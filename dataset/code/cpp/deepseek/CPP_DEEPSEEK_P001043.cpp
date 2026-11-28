Here is the C++ code for your problem:

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int last_internal_node = -1;
    for(int i = 0; i < n; i++) {
        if(arr[i] != 0) {
            last_internal_node = arr[i];
            break;
        }
    }
    cout << last_internal_node << endl;
    return 0;
}
This code takes an array of integers as input and finds the last non-zero value. It works by checking each element in the array from left to right. When it finds a non-zero element, it sets the last_internal_node variable to this value and breaks the loop.