#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        pq.push(num);
        if (i >= k) {
            int top = pq.top();
            pq.pop();
            cout << top << " ";
        }
    }

    while (!pq.empty()) {
        int top = pq.top();
        pq.pop();
        cout << top << " ";
    }

    return 0;
}