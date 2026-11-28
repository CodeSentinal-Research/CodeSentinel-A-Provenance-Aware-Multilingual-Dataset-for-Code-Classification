Here is the C++ code:

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int longestZeroSumSubarray(vector<int>& arr) {
    int sum = 0;
    unordered_map<int, int> mpp;
    int maxLen = 0;

    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        if(sum == 0) {
            maxLen = max(maxLen, i + 1);
        }

        if(mpp.find(sum) != mpp.end()) {
            maxLen = max(maxLen, i - mpp[sum]);
        } else {
            mpp[sum] = i;
        }
    }

    return maxLen;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxLen = longestZeroSumSubarray(arr);
    cout << maxLen << endl;

    return 0;
}

This code first reads the size of the array from the standard input. Then, it reads the array elements from the standard input. The `longestZeroSumSubarray` function is then called with the array as the argument. This function implements the Kadane's algorithm, which is an efficient algorithm for finding the maximum subarray sum in a one-dimensional array.