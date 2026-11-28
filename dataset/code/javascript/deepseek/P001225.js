Sure, I can help you write the JavaScript code for this problem. Here's the code:

function countTilings(n) {
    var dp = [1, 2, 5];
    for (var i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    return dp[n];
}

var n = parseInt(process.argv[2]);
if (n < 1 || n > 1000) {
    console.log("Invalid input. Please enter a number between 1 and 1000.");
} else {
    console.log(countTilings(n));
}

This code uses a dynamic programming approach to solve the problem. It first initializes an array `dp` with the base cases for the number of ways to tile a 2x1 board and a 2x2 board. Then, it iterates from 3 to `n`, calculating the number of ways to tile a 2x`i` board as the sum of the number of ways to tile a 2x`i - 1` board, a 2x`i - 2` board, and a 2x`i - 3` board.

The input handling part is included in the last part of the code. It reads the input from the command line arguments and validates it. If the input is outside the range 1 to 1000, it outputs an error message.