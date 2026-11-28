#include <iostream>
#include <deque>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    deque<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int count = 0;
    deque<int> zeroIndices;
    for (int i = 0; i < N; i++) {
        if (nums[i] == 0) {
            zeroIndices.push_back(i);
        }
        if (zeroIndices.size() > K - 1) {
            zeroIndices.pop_front();
        }
        if (zeroIndices.size() == K) {
            count += (int)zeroIndices.size();
            zeroIndices.pop_front();
        }
    }

    cout << count;
    return 0;
}
This program uses a deque (double-ended queue) to store the indices of the zeroes. It iterates through the input array, and whenever it encounters a zero, it adds its index to the deque.

If the deque is already at capacity (i.e., the size is equal to K), it removes the oldest index from the deque. This is because there is no need to count these zeros when there are already K indices in the deque, so we can safely pop the oldest index.

The count is incremented by the size of the deque at each iteration.

At the end of the program, it prints the count.