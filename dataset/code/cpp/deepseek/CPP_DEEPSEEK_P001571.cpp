Here is the complete C++ code:

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

    deque<int> dq;
    for (int i = 0; i < k; i++) {
        while (!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for (int i = k; i < n; i++) {
        cout << nums[dq.front()] - nums[i - k] << " ";
        while (!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }
        dq.push_back(i);
    }
    cout << nums[dq.front()] - nums[n - 1] << endl;

    return 0;
}

This code first reads the size of the input and the array of integers. It then creates a deque that will be used to find the maximum and minimum in each window. For each window, it checks if the current element is greater than the last element in the deque (i.e., the maximum in the previous window). If it is, it pops the last element from the deque. Then it pushes the current element to the deque. After each window, it calculates the difference between the first and last element in the window, and prints this difference. It then repeats the process for the next window.