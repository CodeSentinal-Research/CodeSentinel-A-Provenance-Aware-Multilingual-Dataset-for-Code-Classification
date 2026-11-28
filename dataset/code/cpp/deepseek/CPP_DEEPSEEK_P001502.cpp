Here is the C++ code for the problem:

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ones = 0, zeros = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) {
            zeros++;
        } else {
            ones++;
        }
    }
    if(zeros > 1) {
        cout << -1;
    } else {
        cout << zeros;
    }
    return 0;
}
This program reads an integer N and a binary array from the input. It then counts the number of 0s and 1s in the array. If there are more than one 0s, it outputs -1 as there's no solution. Otherwise, it outputs the number of 0s as the minimum number of swaps to group all 1s together.