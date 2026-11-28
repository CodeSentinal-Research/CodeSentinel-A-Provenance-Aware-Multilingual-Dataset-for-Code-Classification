Here is the C++ code for the given problem:

#include <iostream>
#include <deque>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    deque<int> q;
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;

        q.push_back(num);

        if(i >= K-1) {
            cout << q.front() << " ";
            q.pop_front();
        }
    }

    return 0;
}

This program uses a deque (double-ended queue) to maintain a sliding window of size K. It takes the input array and a window size, and then iterates through the array. For each element, it adds it to the back of the deque (i.e., the window) and then pops and prints the front of the deque if the window has moved beyond the size K.