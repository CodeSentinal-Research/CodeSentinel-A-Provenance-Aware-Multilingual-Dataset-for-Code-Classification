// P001086 - Multi-Source Shortest Distance
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    const k = parseInt(input[2], 10);
    let ptr = 3;
    const sources = [];
    for (let i = 0; i < k; i++) sources.push(parseInt(input[ptr++], 10));
    const adj = Array.from({ length: n }, () => []);
    for (let i = 0; i < m; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        adj[u].push(v);
        adj[v].push(u);
    }
    const dist = new Array(n).fill(-1);
    const queue = [];
    for (const s of sources) {
        dist[s] = 0;
        queue.push(s);
    }
    while (queue.length > 0) {
        const u = queue.shift();
        for (const v of adj[u]) {
            if (dist[v] === -1) {
                dist[v] = dist[u] + 1;
                queue.push(v);
            }
        }
    }
    console.log(dist.join(" "));
}

main();
