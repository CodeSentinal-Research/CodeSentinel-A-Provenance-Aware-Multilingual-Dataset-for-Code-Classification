Here is the C++ code for the problem:

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int maxSubArraySum(vector<int> a) {
    int size = a.size();
    int maxSoFar = INT_MIN, maxEndingHere = 0;

    for (int i = 0; i < size; i++) {
        maxEndingHere = maxEndingHere + a[i];
        if (maxSoFar < maxEndingHere)
            maxSoFar = maxEndingHere;
        if (maxEndingHere < 0)
            maxEndingHere = 0;
    }
    return maxSoFar;
}

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for(int &i : a) cin >> i;
    cout << maxSubArraySum(a);
    return 0;
}

This program takes as input the size of the array and the elements of the array. It then uses the `maxSubArraySum` function to find the maximum subarray sum.

This function works by iterating over the array and keeping track of the maximum sum of a subarray ending at each position. If the sum of a subarray ending at the current position is greater than the maximum sum, it updates the maximum sum. If the sum of a subarray ending at the current position is negative, it resets the sum to zero. The maximum sum is the maximum sum found so far.