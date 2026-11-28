Here is the C++ code for the given problem:

#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

int sumSubarrayMins(vector<int>& arr) {
    long long sum = 0;
    int n = arr.size();
    vector<int> left(n), right(n);

    left[0] = arr[0];
    right[n-1] = arr[n-1];

    for(int i = 1; i < n; i++)
        left[i] = (left[i-1] + arr[i]) % MOD;
    for(int i = n-2; i >= 0; i--)
        right[i] = (right[i+1] + arr[i]) % MOD;

    for(int i = 0; i < n; i++)
        sum = (sum + min(left[i], right[i]) * arr[i]) % MOD;

    return sum;
}

int main() {
    vector<int> arr = {3,1,2,4};
    cout << sumSubarrayMins(arr) << endl;
    return 0;
}

This code first computes the prefix sum `left` and the suffix sum `right` for the given array `arr`. Then it iterates over the array and for each element, it computes the minimum of `left[i]` and `right[i]` and multiplies it with the element itself. The final result is the sum of all such products. This solution is based on the fact that for each element in the array, the minimum element of the subarray containing this element is exactly `left[i]` and `right[i]`.