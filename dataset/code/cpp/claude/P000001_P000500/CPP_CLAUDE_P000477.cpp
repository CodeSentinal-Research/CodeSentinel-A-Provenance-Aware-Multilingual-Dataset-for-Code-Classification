#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        k %= n;
        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin()+k);
        reverse(arr.begin()+k, arr.end());
    }
};
int main() {
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;
    Solution().rotate(arr, k);
    for (int i = 0; i < n; i++) cout << arr[i] << (i<n-1?" ":"\n");
}
