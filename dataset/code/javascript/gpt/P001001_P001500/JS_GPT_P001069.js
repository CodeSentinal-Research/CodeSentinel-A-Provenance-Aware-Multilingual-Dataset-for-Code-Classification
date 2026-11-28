// P001069 - Shortest Path in a Directed Acyclic Graph
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    const src = parseInt(input[2], 10);
    let ptr = 3;
    const adj = Array.from({ length: n }, () => []);
    const inDegree = new Array(n).fill(0);
    for (let i = 0; i < m; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        const w = parseInt(input[ptr++], 10);
        adj[u].push({ v, w });
        inDegree[v]++;
    }
    const queue = [];
    for (let i = 0; i < n; i++) {
        if (inDegree[i] === 0) queue.push(i);
    }
    const topo = [];
    while (queue.length > 0) {
        const u = queue.shift();
        topo.push(u);
        for (const edge of adj[u]) {
            inDegree[edge.v]--;
            if (inDegree[edge.v] === 0) queue.push(edge.v);
        }
    }
    const dist = new Array(n).fill(Infinity);
    dist[src] = 0;
    for (const u of topo) {
        if (dist[u] !== Infinity) {
            for (const edge of adj[u]) {
                if (dist[u] + edge.w < dist[edge.v]) {
                    dist[edge.v] = dist[u] + edge.w;
                }
            }
        }
    }
    console.log(dist.map(d => (d === Infinity ? "INF" : d)).join(" "));
}

main();
