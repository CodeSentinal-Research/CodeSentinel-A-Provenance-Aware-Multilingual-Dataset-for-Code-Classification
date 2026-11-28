#include <iostream>
#include <vector>
#include <climits>
#include <map>
using namespace std;

map<pair<int, int>, long long> memo;

long long getSum(const vector<int>& freq, int i, int j) {
    long long sum = 0;
    for (int k = i; k <= j; ++k) sum += freq[k];
    return sum;
}

long long solve(const vector<int>& freq, int i, int j) {
    if (i > j) return 0;
    if (i == j) return freq[i];
    
    pair<int, int> key = {i, j};
    if (memo.find(key) != memo.end()) return memo[key];
    
    long long minCost = LLONG_MAX;
    long long sumFreq = getSum(freq, i, j);
    for (int r = i; r <= j; ++r) {
        long long leftCost = solve(freq, i, r - 1);
        long long rightCost = solve(freq, r + 1, j);
        long long cost = leftCost + rightCost + sumFreq;
        if (cost < minCost) minCost = cost;
    }
    return memo[key] = minCost;
}

int main() {
    int n;
    cin >> n;
    vector<int> keys(n), freq(n);
    for (int i = 0; i < n; ++i) cin >> keys[i];
    for (int i = 0; i < n; ++i) cin >> freq[i];
    
    cout << solve(freq, 0, n - 1) << endl;
    return 0;
}
