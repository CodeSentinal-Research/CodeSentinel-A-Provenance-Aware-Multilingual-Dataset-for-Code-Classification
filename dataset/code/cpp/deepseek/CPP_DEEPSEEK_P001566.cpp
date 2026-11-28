Here is the C++ code for the problem:

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    deque<int> deq;
    for (int i = 0; i < N; ++i) {
        while (!deq.empty() && deq.front() < i - K + 1) {
            deq.pop_front();
        }

        while (!deq.empty() && nums[deq.back()] >= nums[i]) {
            deq.pop_back();
        }

        deq.push_back(i);

        if (i >= K - 1) {
            cout << nums[deq.front()] << " ";
        }
    }

    return 0;
}

In this code, we use a deque to store indices of numbers. The deque is used to efficiently pop elements from the front and push elements to the back in constant time. When a new number is added, it is compared with the largest number in the current window and if it's larger, it is popped from the back of the deque. 

Then, the new number is compared with all numbers before it (if any) and if it's smaller, it is popped from the front of the deque. This process continues until the current window has been fully processed.