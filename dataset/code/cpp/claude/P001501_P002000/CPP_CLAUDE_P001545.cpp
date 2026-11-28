#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    pair<int,int> findMaxMin(vector<int>& arr) {
        return {*max_element(arr.begin(),arr.end()), *min_element(arr.begin(),arr.end())};
    }
};
int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;
    auto [mx, mn] = Solution().findMaxMin(arr);
    cout << "Max: " << mx << "\nMin: " << mn << "\n";
}
