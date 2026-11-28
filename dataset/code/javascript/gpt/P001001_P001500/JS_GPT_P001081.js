// P001081 - Find Eulerian Circuit
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    let ptr = 2;
    const degree = new Array(n).fill(0);
    const adj = Array.from({ length: n }, () => []);
    for (let i = 0; i < m; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        adj[u].push(v);
        adj[v].push(u);
        degree[u]++;
        degree[v]++;
    }
    for (let i = 0; i < n; i++) {
        if (degree[i] % 2 !== 0) {
            console.log("NO");
            return;
        }
    }
    console.log("YES");
}

main();
