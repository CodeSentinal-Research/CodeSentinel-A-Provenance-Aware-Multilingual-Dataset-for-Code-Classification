#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    deque<int> d;

    for (int i = 0; i < nums.size(); i++) {
        if (d.size() > 0 && d.front() == i - k) {
            d.pop_front();
        }

        while (!d.empty() && nums[d.back()] < nums[i]) {
            d.pop_back();
        }

        d.push_back(i);

        if (i >= k - 1) {
            res.push_back(nums[d.front()]);
        }
    }

    return res;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> res = maxSlidingWindow(nums, k);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}