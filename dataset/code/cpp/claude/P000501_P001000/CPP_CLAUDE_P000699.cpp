#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> reverseArray(vector<int> arr) {
        reverse(arr.begin(), arr.end());
        return arr;
    }
};
int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;
    auto res = Solution().reverseArray(arr);
    for (int i = 0; i < n; i++) cout << res[i] << (i<n-1?" ":"\n");
}
