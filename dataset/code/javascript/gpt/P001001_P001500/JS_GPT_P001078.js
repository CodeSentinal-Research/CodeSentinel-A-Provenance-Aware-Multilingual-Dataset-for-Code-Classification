// P001078 - Prim's Minimum Spanning Tree
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    let ptr = 2;
    const adj = Array.from({ length: n }, () => []);
    for (let i = 0; i < m; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        const w = parseInt(input[ptr++], 10);
        adj[u].push({ v, w });
        adj[v].push({ v: u, w });
    }
    const inMST = new Array(n).fill(false);
    const key = new Array(n).fill(Infinity);
    key[0] = 0;
    let totalWeight = 0;
    for (let count = 0; count < n; count++) {
        let u = -1, minKey = Infinity;
        for (let v = 0; v < n; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }
        if (u === -1) break;
        inMST[u] = true;
        totalWeight += minKey;
        for (const edge of adj[u]) {
            if (!inMST[edge.v] && edge.w < key[edge.v]) {
                key[edge.v] = edge.w;
            }
        }
    }
    console.log(totalWeight);
}

main();
