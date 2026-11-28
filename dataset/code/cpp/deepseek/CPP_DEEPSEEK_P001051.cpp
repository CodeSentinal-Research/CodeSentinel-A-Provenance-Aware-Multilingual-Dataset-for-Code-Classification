Here is the C++ code for the problem:

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        pq.push(num);
    }

    while (Q--) {
        int type, val;
        cin >> type >> val;

        if (type == 1) {
            pq.push(val);
        } else {
            if (pq.top() >= val) {
                pq.pop();
                pq.push(val);
            }
        }
    }

    while (!pq.empty()) {
        int top = pq.top();
        pq.pop();

        if (top > pq.top()) {
            cout << "INVALID" << endl;
            return 0;
        }
    }

    cout << "VALID" << endl;

    return 0;
}

This program reads the size of the heap and the number of update operations, and then reads the initial values of the heap. After that, it reads the update operations. For each update operation, it pushes the new value into the heap. Finally, it checks if the final heap satisfies the required heap property. If the heap is not valid, it prints "INVALID", otherwise it prints "VALID".