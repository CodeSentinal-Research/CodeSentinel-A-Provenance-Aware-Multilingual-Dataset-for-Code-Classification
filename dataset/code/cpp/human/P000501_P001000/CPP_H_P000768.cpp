#include <iostream>
#include <vector>
using namespace std;

/*
    Problem: Count Unique Binary Search Trees
    -----------------------------------------
    We need to count the number of structurally unique Binary Search Trees (BSTs)
    that can be formed using 'n' distinct nodes labeled 1...n.

    Approach (Bottom-Up Dynamic Programming - Tabulation):
    - This problem reduces to finding the nth Catalan number.
    - Recursive relation:
        countUniqueBST(n) = Σ ( countUniqueBST(i-1) * countUniqueBST(n-i) )
                            for i = 1 to n
      where:
        - (i-1) nodes form the left subtree
        - (n-i) nodes form the right subtree

    - Using tabulation (iterative DP), we fill dp[i] for all values from 2 to n.
    - dp[i] represents the number of unique BSTs that can be formed with i nodes.

    Base Cases:
        dp[0] = 1   (empty tree is a valid BST)
        dp[1] = 1   (only one node forms exactly one BST)

    Time Complexity:
        - O(n^2)
          For each 'i' from 2 to n, we loop from 1 to i for root placement.

    Space Complexity:
        - O(n) for the dp array.
*/

/* Bottom-Up Tabulation Method */
int countBSTTab(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;  // Base cases

    // Build dp table iteratively
    for (int nodes = 2; nodes <= n; nodes++) {
        for (int root = 1; root <= nodes; root++) {
            int leftSubtrees = dp[root - 1];
            int rightSubtrees = dp[nodes - root];
            dp[nodes] += leftSubtrees * rightSubtrees;
        }
    }

    return dp[n];
}

/* Wrapper function */
int countUniqueBST(int n) {
    return countBSTTab(n);
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    int result = countUniqueBST(n);

    cout << "\nNumber of unique Binary Search Trees possible with "
         << n << " nodes = " << result << endl;

    return 0;
}
