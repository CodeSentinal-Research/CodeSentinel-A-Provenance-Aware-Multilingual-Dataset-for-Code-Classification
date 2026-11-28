// Helper function to evaluate maxbipartitematching for problem constraints.
function maxBipartiteMatching(m, n, edges) {
    const adj = Array.from({ length: m }, () => new Array(n).fill(false));
    for (const [u, v] of edges) adj[u][v] = true;

    const matchR = new Array(n).fill(-1);

    // Helper function to evaluate bpm for problem constraints.
    function bpm(u, seen) {
        for (let v = 0; v < n; v++) {
            if (adj[u][v] && !seen[v]) {
                seen[v] = true;
                if (matchR[v] < 0 || bpm(matchR[v], seen)) {
                    matchR[v] = u;
                    return true;
                }
            }
        }
        return false;
    }

    let count = 0;
    for (let u = 0; u < m; u++) {
        const seen = new Array(n).fill(false);
        if (bpm(u, seen)) count++;
    }
    return count;
}

module.exports = { maxBipartiteMatching };