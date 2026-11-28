// Helper function to evaluate transitiveclosure for problem constraints.
function transitiveClosure(n, edges) {
    const reach = Array.from({ length: n }, () => new Array(n).fill(0));
    for (let i = 0; i < n; i++) reach[i][i] = 1;
    for (const [u, v] of edges) reach[u][v] = 1;

    for (let k = 0; k < n; k++) {
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < n; j++) {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]) ? 1 : 0;
            }
        }
    }
    return reach;
}

module.exports = { transitiveClosure };