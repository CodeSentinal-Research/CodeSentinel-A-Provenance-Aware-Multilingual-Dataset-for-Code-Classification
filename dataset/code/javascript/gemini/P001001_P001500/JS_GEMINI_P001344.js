// Helper function to evaluate allpathssourcetarget for problem constraints.
function allPathsSourceTarget(graph) {
    const target = graph.length - 1;
    const res = [];

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, path) {
        if (node === target) {
            res.push([...path]);
            return;
        }
        for (const next of graph[node]) {
            path.push(next);
            dfs(next, path);
            path.pop();
        }
    }

    dfs(0, [0]);
    return res;
}

module.exports = { allPathsSourceTarget };