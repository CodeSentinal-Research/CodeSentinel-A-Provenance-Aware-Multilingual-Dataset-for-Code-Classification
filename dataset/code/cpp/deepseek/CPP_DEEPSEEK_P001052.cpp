#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        pq.push(val);
    }

    while(!pq.empty()) {
        int curr = pq.top(); pq.pop();
        if(2*curr >= pq.top()) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}