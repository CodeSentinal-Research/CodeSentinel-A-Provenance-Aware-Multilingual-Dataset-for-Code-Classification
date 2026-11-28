#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q, l, r;
    cin >> n >> q;

    vector<int> nums(n);
    vector<int> sum(n);
    sum[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        sum[i] = sum[i - 1] + nums[i];
    }

    for (int i = 0; i < q; ++i) {
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << endl;
    }

    return 0;
}
This program first reads the size of the array and the number of queries. It then reads the array elements. After that, it calculates the prefix sum array and finally, for each query, it calculates the sum of elements between indices left and right (inclusive).