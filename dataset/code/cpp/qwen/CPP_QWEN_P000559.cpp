#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    queue<int> q;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        q.push(x);
    }
    // Use another queue to reverse first K
    queue<int> temp;
    for (int i = 0; i < K; i++) {
        temp.push(q.front());
        q.pop();
    }
    // Now push temp in reverse using stack simulation via recursion is not allowed, so use vector
    vector<int> rev;
    while (!temp.empty()) {
        rev.push_back(temp.front());
        temp.pop();
    }
    for (int i = rev.size() - 1; i >= 0; i--) {
        q.push(rev[i]);
    }
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}
