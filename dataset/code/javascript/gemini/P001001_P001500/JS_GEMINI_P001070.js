// Helper function to evaluate isbipartite for problem constraints.
function isBipartite(graph) {
    const n = graph.length;
    const color = new Array(n).fill(0);
    for (let i = 0; i < n; i++) {
        if (color[i] === 0) {
            const q = [i];
            color[i] = 1;
            while (q.length > 0) {
                const u = q.shift();
                for (const v of graph[u]) {
                    if (color[v] === 0) {
                        color[v] = -color[u];
                        q.push(v);
                    } else if (color[v] === color[u]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

module.exports = { isBipartite };