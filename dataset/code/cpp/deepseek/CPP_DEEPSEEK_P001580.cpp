Here's the code:

#include <iostream>
#include <deque>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    deque<int> arr;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    int start = 0, maxLen = 0;
    deque<int> oddIndices;
    for (int i = 0; i < N; i++) {
        if (arr[i] % 2 == 1) {
            oddIndices.push_back(i);
        }
        if (oddIndices.size() > K) {
            start = max(start, oddIndices.front() + 1);
            oddIndices.pop_front();
        }
        maxLen = max(maxLen, (int)oddIndices.size());
    }

    cout << maxLen;

    return 0;
}

This C++ program uses a deque (double-ended queue) to store the odd indices of the array. It starts by initializing `start` and `maxLen` to 0 and 0, respectively. It then iterates over the array. If the current element is odd, it adds the index to the deque. If the deque size exceeds `K`, it removes the element at the front of the deque to maintain the size of the deque to at most `K`. It then updates `maxLen` to be the maximum of `maxLen` and the current deque size. Finally, it prints `maxLen`.