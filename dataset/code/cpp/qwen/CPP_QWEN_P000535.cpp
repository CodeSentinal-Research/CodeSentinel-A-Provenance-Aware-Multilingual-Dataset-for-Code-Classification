#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> solve(vector<int>& deck) {
    sort(deck.begin(), deck.end());
    queue<int> q;
    for (int i = 0; i < deck.size(); i++) q.push(i);
    vector<int> res(deck.size());
    for (int card : deck) {
        res[q.front()] = card; q.pop();
        if (!q.empty()) { q.push(q.front()); q.pop(); }
    }
    return res;
}

int main() {
    int n; cin >> n;
    vector<int> deck(n);
    for(int i = 0; i < n; i++) cin >> deck[i];
    vector<int> ans = solve(deck);
    for(int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
