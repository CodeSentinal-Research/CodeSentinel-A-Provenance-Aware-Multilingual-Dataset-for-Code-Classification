// P001103 - Critical Connections in a Network
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
        adj[u].push(v);
        adj[v].push(u);
    }
    const tin = new Array(n).fill(-1);
    const low = new Array(n).fill(-1);
    let timer = 0;
    const bridges = [];
    function dfs(u, p = -1) {
        tin[u] = low[u] = timer++;
        for (const v of adj[u]) {
            if (v === p) continue;
            if (tin[v] !== -1) {
                low[u] = Math.min(low[u], tin[v]);
            } else {
                dfs(v, u);
                low[u] = Math.min(low[u], low[v]);
                if (low[v] > tin[u]) {
                    bridges.push(u < v ? [u, v] : [v, u]);
                }
            }
        }
    }
    for (let i = 0; i < n; i++) {
        if (tin[i] === -1) dfs(i);
    }
    bridges.sort((a, b) => a[0] - b[0] || a[1] - b[1]);
    for (const b of bridges) console.log(b[0] + " " + b[1]);
}

main();
