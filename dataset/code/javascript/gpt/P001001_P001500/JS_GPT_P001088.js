// P001088 - Count Vertices at Distance K
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 4) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    const src = parseInt(input[2], 10);
    const k = parseInt(input[3], 10);
    let ptr = 4;
    const adj = Array.from({ length: n }, () => []);
    for (let i = 0; i < m; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        adj[u].push(v);
        adj[v].push(u);
    }
    const dist = new Array(n).fill(-1);
    dist[src] = 0;
    const queue = [src];
    let count = 0;
    while (queue.length > 0) {
        const u = queue.shift();
        if (dist[u] === k) count++;
        if (dist[u] < k) {
            for (const v of adj[u]) {
                if (dist[v] === -1) {
                    dist[v] = dist[u] + 1;
                    queue.push(v);
                }
            }
        }
    }
    console.log(count);
}

main();
