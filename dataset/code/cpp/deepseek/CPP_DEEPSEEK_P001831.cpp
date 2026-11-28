Here is the C++ code for the problem:

#include <iostream>
using namespace std;

int numTrees(int n) {
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        dp[i] = 0;
        for(int j = 1; j <= i; j++) {
            dp[i] += dp[j-1] * dp[i-j];
        }
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter the number of keys: ";
    cin >> n;
    if(n < 0 || n > 1000) {
        cout << "Invalid input. Please enter a number between 0 and 1000." << endl;
        return 0;
    }
    cout << "Number of structurally unique Binary Search Trees: " << numTrees(n) << endl;
    return 0;
}

In this code, we use a dynamic programming approach to solve the problem. The dp[i] represents the number of unique BSTs for keys 1 to i. For every key i from 2 to n, we calculate the number of unique BSTs by considering all keys less than i as the root of the tree, and the number of unique BSTs for the left subtree as j-1 (where j ranges from 1 to i), and the number of unique BSTs for the right subtree as i-j. The total number of unique BSTs for keys 1 to n is the sum of all dp[i] (where i ranges from 2 to n).