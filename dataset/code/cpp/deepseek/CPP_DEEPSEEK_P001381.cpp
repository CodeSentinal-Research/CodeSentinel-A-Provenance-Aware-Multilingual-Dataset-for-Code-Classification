Here is the code:

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int longestConsecutiveSequence(vector<int>& nums) {
    unordered_set<int> numSet;
    int maxLength = 0;

    for (int num : nums) {
        if (numSet.find(num) == numSet.end()) {
            int currentNum = num;
            int currentLength = 1;

            while (numSet.find(currentNum + 1) != numSet.end()) {
                currentNum++;
                currentLength++;
            }

            maxLength = max(maxLength, currentLength);
            numSet.insert(currentNum);
        }
    }

    return maxLength;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << longestConsecutiveSequence(nums) << endl;

    return 0;
}
This code firstly reads an integer N and then reads N integers from the input. It then calls the `longestConsecutiveSequence` function and prints the result. The `longestConsecutiveSequence` function uses an unordered set to track the numbers it has seen. It iterates through the input array, and for each number, it checks if the number is in the set. If it is, it increments the current number and current length. If it's not in the set, it increments the current number and updates the max length if necessary.