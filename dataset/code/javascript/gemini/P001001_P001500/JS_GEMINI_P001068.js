// Sorts the input array into ordered sequence.
function topologicalSort(n, edges) {
    const adj = Array.from({ length: n }, () => []);
    const inDeg = new Array(n).fill(0);
    for (const [u, v] of edges) {
        adj[u].push(v);
        inDeg[v]++;
    }
    const q = [];
    for (let i = 0; i < n; i++) {
        if (inDeg[i] === 0) q.push(i);
    }
    const order = [];
    while (q.length > 0) {
        const u = q.shift();
        order.push(u);
        for (const v of adj[u]) {
            if (--inDeg[v] === 0) q.push(v);
        }
    }
    return order;
}

module.exports = { topologicalSort };