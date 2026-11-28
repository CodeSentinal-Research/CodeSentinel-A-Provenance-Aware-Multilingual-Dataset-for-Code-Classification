#include <iostream>
#include <algorithm>
using namespace std;

int Partition(int arr[], int n, int k) {
    if (k == 1) {
        return accumulate(arr, arr + n, 0);
    }

    int inf = n + 1;
    int dp[k + 1][inf];
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = (i == 0) ? 0 : inf;
        }
    }

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[j - 1] > i) {
                dp[i][j] = dp[i][j - 1];
            } else {
                dp[i][j] = min(dp[i][j - 1], dp[i - arr[j - 1]][j - 1] + arr[j - 1]);
            }
        }
    }

    return dp[k][n];
}

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << Partition(arr, n, k);
    return 0;
}

The code defines a function `Partition` that partitions the given array into `k` non-empty subsets such that the maximum subset sum is minimized. The function uses a dynamic programming approach where it calculates the minimum possible maximum subset sum for all possible subset sizes from 1 to `k`. The `accumulate` function is used to calculate the sum of all elements in the array.

The `main` function reads the number of elements in the array and the partition size from the standard input, then reads the array elements from the standard input. The `Partition` function is then called with these inputs to calculate and print the minimum possible maximum subset sum.