Here is a simple C++ code snippet for the problem. This code uses a dynamic programming approach to find the longest increasing subsequences.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int longest = 0;
    for (int i = 0; i < n; i++) {
        longest = max(longest, dp[i]);
    }

    cout << longest << endl;

    return 0;
}

This code first reads the size of the array and the array itself. It then creates a dynamic programming array dp where dp[i] represents the length of the longest increasing subsequence ending with arr[i]. The main loop initializes dp[i] to 1, and then the nested loop finds the longest increasing subsequence ending with arr[i] by comparing it with the longest increasing subsequence ending with arr[j] + 1, where j < i. Finally, it finds the maximum value in dp and prints it as the number of longest increasing subsequences.