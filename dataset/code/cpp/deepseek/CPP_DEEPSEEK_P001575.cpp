Here is the C++ code to solve the given problem:

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    deque<int> Q;
    for (int i = 0; i < K; i++) {
        while (!Q.empty() && A[i] < A[Q.back()]) {
            Q.pop_back();
        }
        Q.push_back(i);
    }

    cout << A[Q.front()] << endl;

    for (int i = K; i < N; i++) {
        if (Q.front() == i - K) {
            Q.pop_front();
        }
        while (!Q.empty() && A[i] < A[Q.back()]) {
            Q.pop_back();
        }
        Q.push_back(i);
        cout << A[Q.front()] << " ";
    }

    return 0;
}

In this code, we use a deque (double-ended queue) to keep track of the indices of the elements in the current window. The deque is used to ensure that the indices are always sorted and that the front of the deque always represents the minimum element in the current window.

In the main function, we first read the size of the array and the window size. We then read the array of integers.

In the loop that runs from 0 to K-1, we pop elements from the back of the deque as long as the current element is smaller than the last element in the deque (which is the minimum element in the previous window). We then push the current index to the back of the deque.

After that, we run a loop from K to N-1. In each iteration, we check if the current index is equal to the index in the front of the deque (which represents the index of the minimum element in the current window), and if it is, we pop the element from the front of the deque. We then repeat the same process as before.

Finally, we print the minimum element in the first window.