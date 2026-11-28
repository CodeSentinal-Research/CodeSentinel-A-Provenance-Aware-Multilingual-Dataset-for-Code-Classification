#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueue(queue<int> &q, int k) {
    stack<int> s;
    for(int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }
    
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    
    for(int i = 0; i < q.size() - k; i++) {
        int ele = q.front();
        q.pop();
        q.push(ele);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    queue<int> q;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        q.push(a);
    }
    reverseQueue(q, k);
    return 0;
}