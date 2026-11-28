// Helper function to evaluate maxflow for problem constraints.
function maxFlow(n, edges, src, sink) {
    const cap = Array.from({ length: n }, () => new Array(n).fill(0));
    for (const [u, v, c] of edges) cap[u][v] += c;

    let flow = 0;
    while (true) {
        const parent = new Array(n).fill(-1);
        parent[src] = -2;
        const curCap = new Array(n).fill(0);
        curCap[src] = Infinity;
        const q = [src];

        while (q.length > 0) {
            const u = q.shift();
            if (u === sink) break;
            for (let v = 0; v < n; v++) {
                if (parent[v] === -1 && cap[u][v] > 0) {
                    parent[v] = u;
                    curCap[v] = Math.min(curCap[u], cap[u][v]);
                    q.push(v);
                }
            }
        }
        if (parent[sink] === -1) break;
        const aug = curCap[sink];
        flow += aug;
        let curr = sink;
        while (curr !== src) {
            const p = parent[curr];
            cap[p][curr] -= aug;
            cap[curr][p] += aug;
            curr = p;
        }
    }
    return flow;
}

module.exports = { maxFlow };