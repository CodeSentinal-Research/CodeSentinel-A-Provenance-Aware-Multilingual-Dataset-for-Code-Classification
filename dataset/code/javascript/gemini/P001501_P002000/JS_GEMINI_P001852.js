// Helper function to evaluate countvalidinsertionseqs for problem constraints.
function countValidInsertionSeqs(root) {
    const MOD = 1000000007n;

    const comb = Array.from({ length: 1005 }, () => new Array(1005).fill(0n));
    for (let i = 0; i <= 1000; i++) {
        comb[i][0] = comb[i][i] = 1n;
        for (let j = 1; j < i; j++) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
        }
    }

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node) {
        if (!node) return [1n, 0];
        const [lCount, lSize] = dfs(node.left);
        const [rCount, rSize] = dfs(node.right);

        const total = lSize + rSize;
        const c = comb[total][lSize];
        const ways = (((lCount * rCount) % MOD) * c) % MOD;
        return [ways, total + 1];
    }

    return Number(dfs(root)[0]);
}

module.exports = { countValidInsertionSeqs };