// P001075 - Bellman-Ford Algorithm
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    const src = parseInt(input[2], 10);
    let ptr = 3;
    const edges = [];
    for (let i = 0; i < m; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        const w = parseInt(input[ptr++], 10);
        edges.push({ u, v, w });
    }
    const dist = new Array(n).fill(Infinity);
    dist[src] = 0;
    for (let i = 0; i < n - 1; i++) {
        for (const e of edges) {
            if (dist[e.u] !== Infinity && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }
    for (const e of edges) {
        if (dist[e.u] !== Infinity && dist[e.u] + e.w < dist[e.v]) {
            console.log("NEGATIVE CYCLE");
            return;
        }
    }
    console.log(dist.map(d => (d === Infinity ? "INF" : d)).join(" "));
}

main();
