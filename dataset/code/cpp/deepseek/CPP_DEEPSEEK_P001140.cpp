Here is the C++ code for the Unbounded Knapsack problem:

#include <iostream>
using namespace std;

int main() {
    int N, W;
    cin >> N >> W;
    
    int weights[N], values[N];
    for(int i=0; i<N; i++) {
        cin >> weights[i] >> values[i];
    }
    
    int dp[N+1][W+1];
    for(int i=0; i<=N; i++) {
        for(int j=0; j<=W; j++) {
            if(i==0 || j==0) dp[i][j] = 0;
            else if(weights[i-1] <= j)
                dp[i][j] = max(values[i-1] + dp[i-1][j-weights[i-1]], dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    
    cout << dp[N][W] << endl;
    
    return 0;
}

This code reads the number of items and the knapsack capacity from the input, and then reads the weights and values of the items. It then initializes a 2D array `dp` where `dp[i][j]` stores the maximum value that can be obtained with a total weight of `j` using the first `i` items. It then fills up the `dp` table using a dynamic programming approach. The last line of the code prints the maximum value that can be obtained.