Here is the C++ code:

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    if (n == 0) return 0;
    if (n == 1) return cost[0];
    if (n == 2) return min(cost[0], cost[1]);
    
    vector<int> dp(n+1, INT_MAX);
    dp[0] = cost[0];
    dp[1] = cost[1];
    
    for(int i=2; i<n; i++){
        dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
    }
    
    return min(dp[n-1], dp[n-2]);
}

int main() {
    int N;
    cin >> N;
    vector<int> cost(N);
    for (int i = 0; i < N; i++) {
        cin >> cost[i];
    }
    int result = minCostClimbingStairs(cost);
    cout << result << endl;
    return 0;
}

This program reads the size of the array and the elements of the array from the standard input. It then calls the `minCostClimbingStairs` function, which calculates and returns the minimum cost required to reach the top of the stairs. The `minCostClimbingStairs` function uses a dynamic programming approach to find the minimum cost. The base cases for the dp array are set as INT_MAX for the first and second element, and the minimum cost of reaching the nth stair is the minimum cost of reaching (n-1)th and (n-2)th stair plus the cost of the nth stair.