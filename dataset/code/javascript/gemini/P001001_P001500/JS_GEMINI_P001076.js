// Helper function to evaluate floydwarshall for problem constraints.
function floydWarshall(n, edges) {
    const dist = Array.from({ length: n }, () => new Array(n).fill(Infinity));
    for (let i = 0; i < n; i++) dist[i][i] = 0;
    for (const [u, v, w] of edges) {
        dist[u][v] = Math.min(dist[u][v], w);
    }
    for (let k = 0; k < n; k++) {
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    return dist.map(row => row.map(d => d === Infinity ? -1 : d));
}

module.exports = { floydWarshall };