function solve(piles, N) {
    let dp = Array(piles.length).fill(0);
    dp[piles.length - 1] = piles[piles.length - 1];

    for (let i = piles.length - 2; i >= 0; i--) {
        dp[i] = Math.max(
            piles[i] + dp[i + 2 * N],
            dp[i + 1]
        );
    }

    return dp[0];
}

process.stdin.on('data', data => {
    const [N, ...piles] = data.toString().split('\n').map(Number);
    console.log(solve(piles, N));
});