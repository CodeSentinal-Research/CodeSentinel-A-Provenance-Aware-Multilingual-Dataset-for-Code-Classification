#include <iostream>

using namespace std;

long long derangement(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 0;
    else if (n == 2)
        return 1;

    long long dp[n+1];
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++) {
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    if (n < 1 || n > 1000000) {
        cout << "Invalid input";
        return 0;
    }

    cout << "The number of derangements is: " << derangement(n);

    return 0;
}