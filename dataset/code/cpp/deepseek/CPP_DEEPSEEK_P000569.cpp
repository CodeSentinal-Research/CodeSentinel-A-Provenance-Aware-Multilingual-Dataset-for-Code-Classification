#include <iostream>
#include <queue>

using namespace std;

queue<int> reverseQueue(queue<int> q) {
    stack<int> s;
    
    while(!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    return q;
}

int main() {
    int N;
    cin >> N;

    queue<int> q;
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    q = reverseQueue(q);

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}