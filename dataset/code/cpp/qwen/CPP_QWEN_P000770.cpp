#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrixChainMultiplication(vector<int>& dims, int i, int j) {
    if (i >= j) return 0;
    int minCost = INT_MAX;
    for (int k = i; k < j; ++k) {
        int cost = matrixChainMultiplication(dims, i, k) + 
                   matrixChainMultiplication(dims, k + 1, j) + 
                   dims[i-1] * dims[k] * dims[j];
        if (cost < minCost) minCost = cost;
    }
    return minCost;
}

int main() {
    int n;
    cin >> n;
    vector<int> dims(n);
    for (int i = 0; i < n; ++i) cin >> dims[i];
    
    cout << matrixChainMultiplication(dims, 1, n - 1) << endl;
    return 0;
}
