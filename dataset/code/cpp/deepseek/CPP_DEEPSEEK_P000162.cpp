#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n, target;
    cin >> n >> target;

    unordered_set<int> nums;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.insert(num);
    }

    int count = 0;
    for (const auto &num : nums) {
        if (nums.find(target - num) != nums.end()) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}