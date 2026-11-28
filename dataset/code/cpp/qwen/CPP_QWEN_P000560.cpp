#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    queue<int> q;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        q.push(x);
    }
    vector<int> first, second;
    for (int i = 0; i < N / 2; i++) {
        first.push_back(q.front()); q.pop();
    }
    for (int i = 0; i < N / 2; i++) {
        second.push_back(q.front()); q.pop();
    }
    queue<int> res;
    for (int i = 0; i < N / 2; i++) {
        res.push(first[i]);
        res.push(second[i]);
    }
    while (!res.empty()) {
        cout << res.front() << " ";
        res.pop();
    }
    cout << endl;
    return 0;
}
