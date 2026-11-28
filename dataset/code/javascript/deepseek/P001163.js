// Function to check if a string can be formed by interleaving
function canInterleave(A, B, C) {
    // Calculate lengths of given strings
    var m = A.length;
    var n = B.length;
    var o = C.length;

    // If lengths of C, A, and B are not compatible for interleaving, return false
    if (o !== m + n) {
        return false;
    }

    // Dynamic programming approach:
    // dp[i][j][k] will be true if C can be formed by interleaving A[0..i-1] and B[0..j-1] and C[0..k-1]
    var dp = new Array(m + 1);
    for (var i = 0; i <= m; i++) {
        dp[i] = new Array(n + 1);
        for (var j = 0; j <= n; j++) {
            dp[i][j] = new Array(o + 1);
            dp[i][j][0] = true; // If C is empty, C can be formed by interleaving A and B
        }
    }

    // Fill in the dp[][][] table
    for (var i = 1; i <= m; i++) {
        for (var j = 1; j <= n; j++) {
            for (var k = 1; k <= o; k++) {
                // Check if C can be formed by interleaving A[0..i-1] and B[0..j-1] and C[0..k-1]
                dp[i][j][k] = (A[i - 1] == C[k - 1] && dp[i - 1][j][k - 1]) || // If last characters are equal, then A can be interleaved with B
                    (B[j - 1] == C[k - 1] && dp[i][j - 1][k - 1]); // If last characters are equal, then B can be interleaved with C
            }
        }
    }

    // Return true if dp[m][n][o] is true, otherwise false
    return dp[m][n][o];
}

// Read input from STDIN
var A = readline();
var B = readline();
var C = readline();

// Write result to STDOUT
console.log(canInterleave(A, B, C) ? 'YES' : 'NO');