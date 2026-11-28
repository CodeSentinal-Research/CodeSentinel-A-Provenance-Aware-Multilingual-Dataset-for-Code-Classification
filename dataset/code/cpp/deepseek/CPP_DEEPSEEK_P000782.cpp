#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q, l, r;
    cin >> n >> q;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> prefix_sums(n + 1);
    prefix_sums[0] = 0;
    for(int i = 1; i <= n; i++) {
        prefix_sums[i] = prefix_sums[i - 1] + nums[i - 1];
    }
    for(int i = 0; i < q; i++) {
        cin >> l >> r;
        cout << prefix_sums[r + 1] - prefix_sums[l] << endl;
    }
    return 0;
}
This code reads the number of elements in the array and the number of queries, and then reads the array itself. It then preprocesses the array by creating a prefix sum array where each element is the sum of the elements before it in the original array.

For each query, it calculates the difference between the sum of the elements before `r` in the prefix sum array and the sum of the elements before `l` in the prefix sum array. This gives the count of elements in the range `[l, r]` in the original array.

It then prints the count of elements in this range.