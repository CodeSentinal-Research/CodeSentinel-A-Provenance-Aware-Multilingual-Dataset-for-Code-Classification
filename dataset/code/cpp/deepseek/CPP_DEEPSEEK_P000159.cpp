#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int minSum = arr[0];
    int maxSum = arr[0];

    for(int i = 1; i < n; i++) {
        minSum = min(minSum + arr[i], arr[i]);
        maxSum = max(maxSum + arr[i], arr[i]);
    }

    cout << maxSum;

    return 0;
}

This C++ program uses Kadane's algorithm to find the smallest sum of any contiguous subarray. It reads the size of the array and the array elements from the input, then it finds the smallest and largest sums of subarrays. The smallest sum is printed as the output.