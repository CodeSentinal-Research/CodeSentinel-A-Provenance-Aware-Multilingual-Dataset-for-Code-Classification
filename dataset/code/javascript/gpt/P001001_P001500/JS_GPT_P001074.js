// P001074 - Dijkstra's Shortest Path
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    const src = parseInt(input[2], 10);
    let ptr = 3;
    const adj = Array.from({ length: n }, () => []);
    for (let i = 0; i < m; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        const w = parseInt(input[ptr++], 10);
        adj[u].push({ v, w });
        adj[v].push({ v: u, w });
    }
    const dist = new Array(n).fill(Infinity);
    dist[src] = 0;
    const pq = [{ u: src, d: 0 }];
    while (pq.length > 0) {
        pq.sort((a, b) => a.d - b.d);
        const { u, d } = pq.shift();
        if (d > dist[u]) continue;
        for (const edge of adj[u]) {
            if (dist[u] + edge.w < dist[edge.v]) {
                dist[edge.v] = dist[u] + edge.w;
                pq.push({ u: edge.v, d: dist[edge.v] });
            }
        }
    }
    console.log(dist.map(d => (d === Infinity ? -1 : d)).join(" "));
}

main();
