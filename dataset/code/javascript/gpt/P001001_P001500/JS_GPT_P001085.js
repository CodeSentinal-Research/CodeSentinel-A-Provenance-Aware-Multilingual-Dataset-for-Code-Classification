// P001085 - Number of Distinct Paths in a DAG
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 4) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    const src = parseInt(input[2], 10);
    const dest = parseInt(input[3], 10);
    let ptr = 4;
    const adj = Array.from({ length: n }, () => []);
    const inDegree = new Array(n).fill(0);
    for (let i = 0; i < m; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        adj[u].push(v);
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
        for (const v of adj[u]) {
            inDegree[v]--;
            if (inDegree[v] === 0) queue.push(v);
        }
    }
    const ways = new Array(n).fill(0n);
    ways[src] = 1n;
    for (const u of topo) {
        if (ways[u] > 0n) {
            for (const v of adj[u]) {
                ways[v] += ways[u];
            }
        }
    }
    console.log(ways[dest].toString());
}

main();
