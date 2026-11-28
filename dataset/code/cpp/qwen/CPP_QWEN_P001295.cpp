#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> weights(n);
    for (int i = 0; i < n; ++i) cin >> weights[i];
    
    vector<long long> prefixSum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixSum[i+1] = prefixSum[i] + weights[i];
    }
    
    vector<long long> cutCosts;
    for (int i = 0; i < n - 1; ++i) {
        cutCosts.push_back(prefixSum[i+1] * (prefixSum[n] - prefixSum[i+1]));
    }
    
    sort(cutCosts.begin(), cutCosts.end());
    
    long long minScore = 0, maxScore = 0;
    for (int i = 0; i < k - 1; ++i) {
        minScore += cutCosts[i];
    }
    for (int i = cutCosts.size() - 1; i >= (int)cutCosts.size() - (k - 1); --i) {
        maxScore += cutCosts[i];
    }
    
    cout << maxScore - minScore << endl;
    return 0;
}
