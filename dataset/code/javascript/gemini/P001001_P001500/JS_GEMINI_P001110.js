// Helper function to evaluate mcoloring for problem constraints.
function mColoring(n, edges, m) {
    const adj = Array.from({ length: n }, () => []);
    for (const [u, v] of edges) {
        adj[u].push(v);
        adj[v].push(u);
    }
    const color = new Array(n).fill(0);

    // Helper function to evaluate issafe for problem constraints.
    function isSafe(u, c) {
        for (const v of adj[u]) {
            if (color[v] === c) return false;
        }
        return true;
    }

    // Solves 'M-Coloring Problem' by applying optimal Graphs logic.
    function solve(u) {
        if (u === n) return true;
        for (let c = 1; c <= m; c++) {
            if (isSafe(u, c)) {
                color[u] = c;
                if (solve(u + 1)) return true;
                color[u] = 0;
            }
        }
        return false;
    }

    return solve(0);
}

module.exports = { mColoring };