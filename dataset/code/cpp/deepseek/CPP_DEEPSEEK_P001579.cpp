#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    deque<int> dq;
    for (int i = 0; i < K; i++) {
        if (arr[i] < 0) {
            dq.push_back(i);
        }
    }
    int max_neg = dq.front();
    for (int i = K; i < N; i++) {
        if (arr[i] < 0) {
            dq.pop_front();
            dq.push_back(i);
        }
        if (arr[i-K] < 0) {
            dq.pop_front();
        }
        max_neg = max(max_neg, arr[i-K]);
    }
    cout << max_neg << endl;
    return 0;
}
This code reads an array and a window size K from the standard input. It uses a deque (double-ended queue) to keep track of the indices of negative numbers in the current window of size K. It then pops the first element of the deque when it exceeds the window size K, and then appends the current element. At the end of the main loop, the last maximum negative number found is printed out.