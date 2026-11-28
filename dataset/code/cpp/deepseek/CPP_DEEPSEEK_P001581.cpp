#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int start = 0, end = 0;
    deque<int> negatives;
    int maxLength = 0;

    while (end < n) {
        if (nums[end] < 0 && negatives.size() < k) {
            negatives.push_back(nums[end]);
        } else {
            if (negatives.front() < 0) {
                negatives.pop_front();
            } else {
                if (negatives.size() == k) {
                    start = negatives.front();
                    while (start != nums[start]) {
                        negatives.pop_front();
                    }
                    negatives.pop_front();
                }
            }
        }
        if (negatives.size() == 0) {
            maxLength = max(maxLength, end - start + 1);
        }
        end++;
    }

    cout << maxLength << "\n";
    return 0;
}