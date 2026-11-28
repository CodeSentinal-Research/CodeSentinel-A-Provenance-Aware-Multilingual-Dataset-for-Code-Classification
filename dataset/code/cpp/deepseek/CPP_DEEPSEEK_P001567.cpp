#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int countCompleteSubarrays(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int distinctCount = s.size();
    int count = 0;

    for (int i = 0; i < nums.size(); i++) {
        unordered_set<int> seen;
        for (int j = i; j < nums.size(); j++) {
            if (seen.find(nums[j]) != seen.end()) {
                break;
            }
            seen.insert(nums[j]);
            count++;
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << countCompleteSubarrays(nums) << endl;

    return 0;
}