#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            pq.push(num);
        }
    }

    for (int i = 0; i < k - 1; i++) {
        pq.pop();
    }

    cout << pq.top() << endl;

    return 0;
}