function bfs(adj, src, n) {
    const visited = new Array(n + 1).fill(false);
    const queue = [src];
    visited[src] = true;
    const result = [];
    while (queue.length) {
        const u = queue.shift();
        result.push(u);
        for (const v of (adj[u] || [])) {
            if (!visited[v]) { visited[v] = true; queue.push(v); }
        }
    }
    return result;
}

module.exports = { bfs };
