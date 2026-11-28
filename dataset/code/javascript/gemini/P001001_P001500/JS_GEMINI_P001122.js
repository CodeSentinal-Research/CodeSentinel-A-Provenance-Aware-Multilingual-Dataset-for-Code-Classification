// Helper function to evaluate eventualsafenodes for problem constraints.
function eventualSafeNodes(graph) {
    const n = graph.length;
    const color = new Array(n).fill(0);

    // Helper function to evaluate dfs for problem constraints.
    function dfs(u) {
        color[u] = 1;
        for (const v of graph[u]) {
            if (color[v] === 1 || (color[v] === 0 && !dfs(v))) {
                return false;
            }
        }
        color[u] = 2;
        return true;
    }

    const res = [];
    for (let i = 0; i < n; i++) {
        if (color[i] === 2 || (color[i] === 0 && dfs(i))) {
            res.push(i);
        }
    }
    return res;
}

module.exports = { eventualSafeNodes };