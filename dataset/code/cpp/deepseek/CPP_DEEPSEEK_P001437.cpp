#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    unordered_set<int> numSet;
    for (int num : nums) {
        if (numSet.find(2 * num) != numSet.end()) {
            cout << "YES" << endl;
            return 0;
        }
        numSet.insert(num);
    }

    cout << "NO" << endl;
    return 0;
}