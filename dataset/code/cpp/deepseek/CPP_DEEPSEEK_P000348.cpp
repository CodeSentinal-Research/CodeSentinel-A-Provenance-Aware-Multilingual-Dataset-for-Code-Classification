#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    long long dp[n+1][2];
    dp[0][0] = 1; 
    
    for(int i = 1; i <= n; i++) {
        dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % 1000000007;
        dp[i][1] = dp[i-1][0]; 
    }
    
    cout << dp[n][0];
    
    return 0;
}

This code will output the number of possible attendance records of length n that make a student eligible for an award modulo 10^9+7. The state transition equations are derived from the transition matrix form of the given problem. The dp[i][j] represents the number of possible attendance records of length i with exactly j students present. If we have 0 students, the number of valid records is the same as the number of invalid records, i.e., dp[i][0] = dp[i-1][0]. For each i from 1 to n, the number of valid records can be derived from the number of valid records (dp[i-1][0]) and the number of valid records (dp[i-1][1]) by considering whether the student is present or not.