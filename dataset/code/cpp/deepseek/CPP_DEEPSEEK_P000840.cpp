#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int splitBags(int n, vector<int> nums, int maxOperations) {
    int totalBalls = 0;
    for (int num : nums) {
        totalBalls += num;
    }

    int limit = totalBalls / 2;
    sort(nums.begin(), nums.end(), greater<int>());

    int operations = 0;
    for (int num : nums) {
        if (num > limit) {
            if (totalBalls - num > limit) {
                limit = totalBalls - num;
                operations++;
            } else {
                totalBalls -= num;
            }
        }

        if (operations > maxOperations) {
            return totalBalls;
        }
    }

    return totalBalls;
}

int main() {
    int n, maxOperations;
    vector<int> nums;

    cin >> n >> maxOperations;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    cout << splitBags(n, nums, maxOperations) << "\n";

    return 0;
}