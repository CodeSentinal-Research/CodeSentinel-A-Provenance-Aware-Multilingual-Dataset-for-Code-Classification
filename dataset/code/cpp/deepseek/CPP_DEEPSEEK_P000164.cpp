#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    unordered_set<int> numSet;
    int count = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(numSet.find(target - nums[i] - nums[j]) != numSet.end()) {
                count++;
            } else {
                numSet.insert(nums[i]);
                numSet.insert(nums[j]);
            }
        }
    }

    cout << count << "\n";

    return 0;
}