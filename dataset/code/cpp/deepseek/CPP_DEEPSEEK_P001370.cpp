#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;

    vector<int> nums(s.size());
    for (int i = 0; i < s.size(); i++) {
        nums[i] = s[i] - '0';
    }

    for (int i = 0; i < k; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] > nums[maxIdx]) {
                maxIdx = j;
            }
        }
        swap(nums[i], nums[maxIdx]);
    }

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
    }
    cout << "\n";

    return 0;
}