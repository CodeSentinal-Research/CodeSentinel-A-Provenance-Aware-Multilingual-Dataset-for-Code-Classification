#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Queue {
public:
    stack<int> s1, s2;

    void enqueue(int x) {
        s1.push(x);
    }

    int dequeue() {
        if(s1.empty() && s2.empty()) {
            cout << "Queue is empty" << endl;
            exit(0);
        }

        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int x = s2.top();
        s2.pop();
        return x;
    }

    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    Queue q;
    int n;
    cin >> n;

    while(n--) {
        string op;
        cin >> op;

        if(op == "push") {
            int x;
            cin >> x;
            q.enqueue(x);
        } else if(op == "pop") {
            cout << q.dequeue() << endl;
        } else if(op == "peek") {
            cout << (q.isEmpty() ? "Queue is empty" : q.dequeue()) << endl;
            q.enqueue(q.dequeue());
        } else if(op == "empty") {
            cout << (q.isEmpty() ? "Yes" : "No") << endl;
        }
    }

    return 0;
}