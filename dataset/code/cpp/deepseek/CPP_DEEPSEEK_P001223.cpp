Here is the C++ code:

#include <iostream>
using namespace std;

int countBinaryStrings(int N) {
    if (N <= 0) return 0;
    if (N == 1) return 2;

    int* dp = new int[N + 1];
    dp[0] = 0;
    dp[1] = 2;

    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int result = dp[N];
    delete[] dp;

    return result;
}

int main() {
    int N;
    cin >> N;

    if (N < 1 || N > 100000) {
        cout << "Invalid input" << endl;
        return 1;
    }

    cout << countBinaryStrings(N) << endl;

    return 0;
}

This code creates a dynamic programming array `dp` where `dp[i]` represents the number of valid binary strings of length `i`. It uses the principle of dynamic programming to fill up the array in a bottom-up manner.

The base cases are `dp[0] = 0` and `dp[1] = 2` because the binary string of length 0 is an empty string, and the binary string of length 1 can be either "0" or "1".

For length 2 or more, we have `dp[i] = dp[i - 1] + dp[i - 2]`, where `dp[i - 1]` and `dp[i - 2]` represent the binary strings of length `i - 1` and `i - 2`, respectively.

Finally, we return the result from `dp[N]`.