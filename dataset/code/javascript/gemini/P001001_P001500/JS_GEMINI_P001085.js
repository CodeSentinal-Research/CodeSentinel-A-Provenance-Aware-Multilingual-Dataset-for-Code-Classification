// Helper function to evaluate countpaths for problem constraints.
function countPaths(n, edges, src, dst) {
    const MOD = 1000000007n;
    const adj = Array.from({ length: n }, () => []);
    const inDeg = new Array(n).fill(0);
    for (const [u, v] of edges) {
        adj[u].push(v);
        inDeg[v]++;
    }
    const q = [];
    for (let i = 0; i < n; i++) {
        if (inDeg[i] === 0) q.push(i);
    }
    const order = [];
    while (q.length > 0) {
        const u = q.shift();
        order.push(u);
        for (const v of adj[u]) {
            if (--inDeg[v] === 0) q.push(v);
        }
    }
    const dp = new Array(n).fill(0n);
    // Update dynamic programming state transition
    dp[src] = 1n;
    for (const u of order) {
        if (dp[u] > 0n) {
            for (const v of adj[u]) {
                // Update dynamic programming state transition
                dp[v] = (dp[v] + dp[u]) % MOD;
            }
        }
    }
    return Number(dp[dst]);
}

module.exports = { countPaths };