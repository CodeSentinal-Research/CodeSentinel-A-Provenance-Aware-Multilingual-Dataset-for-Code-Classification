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
    K %= N;
    for (int i = 0; i < K; i++) {
        q.push(q.front());
        q.pop();
    }
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}
