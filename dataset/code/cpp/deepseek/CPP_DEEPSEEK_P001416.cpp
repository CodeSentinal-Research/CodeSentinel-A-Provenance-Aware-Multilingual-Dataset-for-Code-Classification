#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    unordered_map<int, int> count;
    for (int num : nums) {
        ++count[num];
    }

    int ans = 0;
    for (int num : nums) {
        if (count[num] && count[num + 1]) {
            ans = max(ans, count[num] + count[num + 1]);
        } else if (!count[num] && count[num + 1]) {
            ans = max(ans, count[num + 1]);
        } else if (count[num] && !count[num + 1]) {
            ans = max(ans, count[num]);
        }
    }

    cout << ans << endl;

    return 0;
}