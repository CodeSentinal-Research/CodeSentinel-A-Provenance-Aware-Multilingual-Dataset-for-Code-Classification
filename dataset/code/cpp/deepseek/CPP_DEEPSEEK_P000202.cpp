#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_set<int> nums;
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (nums.find(num) == nums.end()) {
            nums.insert(num);
            int left = num - 1, right = num + 1;
            while (nums.find(left) != nums.end()) nums.erase(left--);
            while (nums.find(right) != nums.end()) nums.erase(right++);
            maxLength = max(maxLength, right - left - 1);
        }
    }

    cout << maxLength << endl;
    return 0;
}