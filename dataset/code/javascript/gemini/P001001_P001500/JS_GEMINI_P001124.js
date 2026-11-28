// Helper function to evaluate findcheapestprice for problem constraints.
function findCheapestPrice(n, flights, src, dst, k) {
    let dist = new Array(n).fill(Infinity);
    dist[src] = 0;

    for (let i = 0; i <= k; i++) {
        const tmp = [...dist];
        for (const [u, v, w] of flights) {
            if (dist[u] !== Infinity && dist[u] + w < tmp[v]) {
                tmp[v] = dist[u] + w;
            }
        }
        dist = tmp;
    }
    return dist[dst] === Infinity ? -1 : dist[dst];
}

module.exports = { findCheapestPrice };