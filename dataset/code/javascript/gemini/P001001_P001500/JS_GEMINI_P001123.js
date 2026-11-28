// Helper function to evaluate findthecity for problem constraints.
function findTheCity(n, edges, distanceThreshold) {
    const dist = Array.from({ length: n }, () => new Array(n).fill(Infinity));
    for (let i = 0; i < n; i++) dist[i][i] = 0;
    for (const [u, v, w] of edges) {
        dist[u][v] = dist[v][u] = w;
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

    let minReachable = Infinity;
    let ans = -1;
    for (let i = 0; i < n; i++) {
        let reachable = 0;
        for (let j = 0; j < n; j++) {
            if (i !== j && dist[i][j] <= distanceThreshold) reachable++;
        }
        if (reachable <= minReachable) {
            minReachable = reachable;
            ans = i;
        }
    }
    return ans;
}

module.exports = { findTheCity };