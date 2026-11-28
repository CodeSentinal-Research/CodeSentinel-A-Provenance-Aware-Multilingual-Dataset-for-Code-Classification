// P001080 - Find All Articulation Points
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
    const isCut = new Array(n).fill(false);
    let timer = 0;
    function dfs(u, p = -1) {
        tin[u] = low[u] = timer++;
        let children = 0;
        for (const v of adj[u]) {
            if (v === p) continue;
            if (tin[v] !== -1) {
                low[u] = Math.min(low[u], tin[v]);
            } else {
                dfs(v, u);
                low[u] = Math.min(low[u], low[v]);
                if (low[v] >= tin[u] && p !== -1) {
                    isCut[u] = true;
                }
                children++;
            }
        }
        if (p === -1 && children > 1) {
            isCut[u] = true;
        }
    }
    for (let i = 0; i < n; i++) {
        if (tin[i] === -1) dfs(i);
    }
    const points = [];
    for (let i = 0; i < n; i++) {
        if (isCut[i]) points.push(i);
    }
    console.log(points.join(" "));
}

main();
