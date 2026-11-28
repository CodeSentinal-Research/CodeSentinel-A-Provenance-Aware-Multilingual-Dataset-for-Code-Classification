#include <iostream>
#include <queue>

using namespace std;

int main() {
    int Q;
    cin >> Q;
    priority_queue<int> pq;

    for (int i = 0; i < Q; i++) {
        int operation;
        cin >> operation;

        if (operation == 1) {
            int value;
            cin >> value;
            pq.push(value);
        } else if (operation == 2) {
            if (!pq.empty()) {
                pq.pop();
            }
        } else if (operation == 3) {
            if (!pq.empty()) {
                cout << pq.top() << endl;
            } else {
                cout << "Queue is empty" << endl;
            }
        }
    }

    return 0;
}
This C++ program reads the number of operations Q, then for each operation, it checks the type of operation. If the operation is to insert a value, it inserts the value into the priority queue. If the operation is to pop the highest priority element, it pops the highest priority element from the priority queue. If the operation is to retrieve the highest priority element, it retrieves and prints the highest priority element from the priority queue. If the priority queue is empty, it prints "Queue is empty".