#include <iostream>
using namespace std;

int countCircularPermutations(int N) {
    if (N <= 1) return 1;
    long long dp[N + 1];
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= N; i++) {
        dp[i] = 0;
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
        dp[i] %= 1000000007; 
    }

    long long total = 0;
    for (int i = 0; i < N; i++) {
        total += dp[i] * dp[N];
        total %= 1000000007;
    }

    return (int)total;
}

int main() {
    int N;
    cout << "Enter the number of objects: ";
    cin >> N;

    if (N < 1 || N > 20) {
        cout << "Invalid input! Please enter a number between 1 and 20." << endl;
        return 0;
    }

    cout << "Number of circular arrangements: " << countCircularPermutations(N) << endl;

    return 0;
}