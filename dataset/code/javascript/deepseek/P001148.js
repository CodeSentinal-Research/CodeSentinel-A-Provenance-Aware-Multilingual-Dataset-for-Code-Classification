Here's the JavaScript code for the problem:

// JavaScript program for Edit Distance

function editDistance(str1, str2, m, n) {
    // Create a table to store results of subproblems
    let dp = new Array(m + 1);
    for(let i = 0; i <= m; i++)
        dp[i] = new Array(n + 1);

    // Fill dp[][] in bottom-up manner
    for(let i = 0; i <= m; i++) {
        for(let j = 0; j <= n; j++) {
            if(i == 0)
                dp[i][j] = j; // Minimum operations = j
            else if(j == 0)
                dp[i][j] = i; // Minimum operations = i
            else if(str1.charAt(i - 1) == str2.charAt(j - 1))
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + Math.min(dp[i][j - 1],  // Insert
                                     Math.min(dp[i - 1][j],  // Remove
                                             dp[i - 1][j - 1])); // Substitute
        }
    }
    return dp[m][n];
}

// Driver code
let str1 = "kitten";
let str2 = "sitting";
let m = str1.length;
let n = str2.length;
console.log(`Edit distance between ${str1} and ${str2} is ${editDistance(str1, str2, m, n)}`);

This program uses a dynamic programming approach to solve the Edit Distance problem. It creates a 2D array (or a matrix) dp[][] where dp[i][j] represents the minimum number of operations required to convert the first i characters of str1 to the first j characters of str2. The base cases are when i = 0 or j = 0, in which case we simply need to perform i or j operations (insert or remove). For all other cases, we need to find the minimum of three operations: insert, remove, and substitute.