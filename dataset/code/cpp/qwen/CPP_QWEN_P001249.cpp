#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ropes(n);
    for (int i = 0; i < n; ++i) cin >> ropes[i];
    
    priority_queue<int, vector<int>, greater<int>> pq(ropes.begin(), ropes.end());
    
    long long cost = 0;
    while (pq.size() > 1) {
        int r1 = pq.top(); pq.pop();
        int r2 = pq.top(); pq.pop();
        int newRope = r1 + r2;
        cost += newRope;
        pq.push(newRope);
    }
    
    cout << cost << endl;
    return 0;
}
