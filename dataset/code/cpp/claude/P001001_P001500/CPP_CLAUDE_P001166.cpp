#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findMax(vector<int>& arr) {
        return *max_element(arr.begin(), arr.end());
    }
};
int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;
    cout << Solution().findMax(arr) << "\n";
}
