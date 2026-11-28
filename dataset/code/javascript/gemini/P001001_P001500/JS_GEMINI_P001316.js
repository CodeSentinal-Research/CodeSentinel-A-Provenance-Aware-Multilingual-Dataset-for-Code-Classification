// Helper function to evaluate graphcoloring for problem constraints.
function graphColoring(adj, m, v) {
    const color = new Array(v).fill(0);

    // Helper function to evaluate issafe for problem constraints.
    function isSafe(node, c) {
        for (let i = 0; i < v; i++) {
            if (adj[node][i] === 1 && color[i] === c) return false;
        }
        return true;
    }

    // Solves 'M-Coloring Problem' by applying optimal Backtracking logic.
    function solve(node) {
        if (node === v) return true;
        for (let c = 1; c <= m; c++) {
            if (isSafe(node, c)) {
                color[node] = c;
                if (solve(node + 1)) return true;
                color[node] = 0;
            }
        }
        return false;
    }

    return solve(0);
}

module.exports = { graphColoring };