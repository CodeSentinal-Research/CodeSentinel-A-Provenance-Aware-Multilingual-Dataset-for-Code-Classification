#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& arr) {
        return *min_element(arr.begin(), arr.end());
    }
};
int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;
    cout << Solution().findMin(arr) << "\n";
}
