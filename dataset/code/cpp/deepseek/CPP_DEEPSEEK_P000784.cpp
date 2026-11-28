Here's the complete C++ code:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> prefixSum(n + 1, 0);
    for(int i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + (nums[i] % 2 != 0 ? 1 : 0);
    }

    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << prefixSum[r] - prefixSum[l] << endl;
    }

    return 0;
}

This code first reads the size of the array `n` and the number of queries `q`. It then reads the array of integers. 

We use a prefix sum to count the number of odd numbers in the array. The prefix sum array `prefixSum` is initialized with all elements set to 0 and then for each element in the array, we add 1 to the corresponding position in the prefix sum array if the current number is odd.

Finally, for each query, we calculate the number of odd numbers between the given indices (inclusive) and print it.