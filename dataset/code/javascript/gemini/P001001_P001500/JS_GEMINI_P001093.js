// Helper function to evaluate areisomorphic for problem constraints.
function areIsomorphic(n, edges1, edges2) {
    if (edges1.length !== edges2.length) return false;
    const adj1 = Array.from({ length: n }, () => new Array(n).fill(false));
    for (const [u, v] of edges1) adj1[u][v] = adj1[v][u] = true;

    const adj2 = Array.from({ length: n }, () => new Array(n).fill(false));
    for (const [u, v] of edges2) adj2[u][v] = adj2[v][u] = true;

    const p = new Array(n);
    const used = new Array(n).fill(false);

    // Solves 'Check Graph Isomorphism' by applying optimal Graphs logic.
    function solve(idx) {
        if (idx === n) {
            for (let i = 0; i < n; i++) {
                for (let j = 0; j < n; j++) {
                    if (adj1[i][j] !== adj2[p[i]][p[j]]) return false;
                }
            }
            return true;
        }
        for (let i = 0; i < n; i++) {
            if (!used[i]) {
                used[i] = true;
                p[idx] = i;
                if (solve(idx + 1)) return true;
                used[i] = false;
            }
        }
        return false;
    }
    return solve(0);
}

module.exports = { areIsomorphic };