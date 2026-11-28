// Helper function to evaluate networkdelaytime for problem constraints.
function networkDelayTime(times, n, k) {
    const adj = Array.from({ length: n + 1 }, () => []);
    for (const [u, v, w] of times) adj[u].push([v, w]);

    const dist = new Array(n + 1).fill(Infinity);
    dist[k] = 0;
    const vis = new Array(n + 1).fill(false);

    for (let iter = 0; iter < n; iter++) {
        let u = -1;
        for (let i = 1; i <= n; i++) {
            if (!vis[i] && (u === -1 || dist[i] < dist[u])) u = i;
        }
        if (u === -1 || dist[u] === Infinity) break;
        vis[u] = true;
        for (const [v, w] of adj[u]) {
            if (dist[u] + w < dist[v]) dist[v] = dist[u] + w;
        }
    }
    let max = 0;
    for (let i = 1; i <= n; i++) {
        if (dist[i] === Infinity) return -1;
        max = Math.max(max, dist[i]);
    }
    return max;
}

module.exports = { networkDelayTime };