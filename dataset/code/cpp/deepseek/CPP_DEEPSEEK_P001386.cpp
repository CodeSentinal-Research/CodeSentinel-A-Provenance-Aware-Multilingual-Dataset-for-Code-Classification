Here is the complete C++ code for the problem.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];

    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return fast;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n + 1);

    for (int i = 0; i <= n; i++) {
        cin >> nums[i];
    }

    int duplicate = findDuplicate(nums);

    cout << duplicate << endl;

    return 0;
}

In this code, we use Floyd's Cycle-Finding Algorithm to find the duplicated number. The algorithm is a modification of the slow-fast pointer approach.

The main idea of the algorithm is that we have two pointers, slow and fast. Slow moves one step at a time, while fast moves two steps at a time. If there is a cycle in the list, the fast pointer will eventually catch up to the slow pointer.

The problem statement says that the input numbers are between 1 and N, so we use the first number as our initial slow pointer, and the second number as our initial fast pointer. We then move both pointers one step at a time until they meet at the start of the cycle.

Once they meet, we reset the slow pointer to the start of the list and move it one step at a time until it meets again at the start of the cycle. This step will be the start of the duplicated number.