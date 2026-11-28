Here is a C++ solution using prefix sum:

#include <iostream>
#include <vector>

using namespace std;

vector<int> solve(int n, vector<int> nums, int q) {
    vector<int> prefixSum(n + 1);
    for (int i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] ^ nums[i];
    }

    vector<int> ans(q);
    for (int i = 0; i < q; i++) {
        int l = nums[i] ^ prefixSum[i];
        int r = prefixSum[n] ^ prefixSum[i] ^ nums[i];
        ans[i] = l ^ r;
    }
    return ans;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> queries(q, 0);
    for (int i = 0; i < q; i++) {
        cin >> queries[i];
    }
    vector<int> ans = solve(n, nums, q);
    for (int i = 0; i < q; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}

This code first creates a prefix sum array using the input array. Then, for each query, it calculates the XOR of the elements in the query range using the prefix sum array. The XOR for each query is then printed.