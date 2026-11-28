Here is the C++ code that should solve the problem:

#include <iostream>
#include <vector>

using namespace std;

bool subsetSum(int N, int S, vector<int> &nums) {
    bool dp[N+1][S+1];

    for(int i=0; i<=N; i++) {
        dp[i][0] = true;
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=S; j++) {
            if(j < nums[i-1]) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
    }

    return dp[N][S];
}

int main() {
    int N, S;
    cin >> N >> S;

    vector<int> nums(N);
    for(int i=0; i<N; i++) {
        cin >> nums[i];
    }

    if(subsetSum(N, S, nums)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}

This code uses dynamic programming to solve the subset sum problem. The `dp` matrix is initialized with `false` for all elements and then filled up by iterating over the numbers and their sums. Finally, the last element of the matrix is checked to see if it can be a subset of the target sum.