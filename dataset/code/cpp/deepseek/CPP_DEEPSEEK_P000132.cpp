Here is the C++ code for the given problem:

#include <iostream>
#include <vector>

using namespace std;

int equilibriumIndex(vector<int> &arr) {
    int n = arr.size();
    int leftSum = 0, rightSum = 0;
    for(int i = 0; i < n; i++) {
        rightSum += arr[i];
    }
    for(int i = 0; i < n; i++) {
        rightSum -= arr[i];
        if(leftSum == rightSum) {
            return i;
        }
        leftSum += arr[i];
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = equilibriumIndex(arr);
    if(result != -1) {
        cout << result << endl;
    } else {
        cout << "Equilibrium index does not exist." << endl;
    }
    return 0;
}

This program reads an integer `n` followed by `n` integers. It then calculates the sum of the right side of the array and subtracts the current element from the right sum. If the sum is equal to the left sum at any point, that's the equilibrium index. If no equilibrium index is found, it prints out a message saying "Equilibrium index does not exist."