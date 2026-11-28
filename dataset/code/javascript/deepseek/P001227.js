Here is a JavaScript code for the problem:

process.stdin.resume();
process.stdin.on('data', function(data) {
    var N = parseInt(data);
    if (N < 1 || N > 1000) {
        console.log('Invalid input! Please enter a number between 1 and 1000.');
        process.stdin.pause();
    } else {
        console.log(countDerangements(N));
    }
});

function countDerangements(n) {
    if (n === 1) return 0;
    if (n === 2) return 1;

    let dp = [0, 1];

    for (let i = 2; i <= n; i++) {
        dp.push( (i - 1) * ( dp[i - 1] + dp[i - 2] * (i - 1) ) );
    }

    return dp[n];
}

This code is a simple implementation of the derangement counting algorithm. The algorithm is based on the dynamic programming concept. It uses an array `dp` to store the computed values, and fills it up in a bottom-up manner. This way, we can use the previously computed results to compute the current result, reducing the computational complexity.