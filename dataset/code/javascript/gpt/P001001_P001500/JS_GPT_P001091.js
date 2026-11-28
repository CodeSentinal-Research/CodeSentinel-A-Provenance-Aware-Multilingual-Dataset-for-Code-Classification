// P001091 - Lowest Common Ancestor Queries
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const q = parseInt(input[1], 10);
    let ptr = 2;
    const adj = Array.from({ length: n }, () => []);
    for (let i = 0; i < n - 1; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        adj[u].push(v);
        adj[v].push(u);
    }
    const parent = new Array(n).fill(-1);
    const depth = new Array(n).fill(0);
    const queue = [0];
    parent[0] = 0;
    while (queue.length > 0) {
        const u = queue.shift();
        for (const v of adj[u]) {
            if (v !== parent[u]) {
                parent[v] = u;
                depth[v] = depth[u] + 1;
                queue.push(v);
            }
        }
    }
    function lca(u, v) {
        while (depth[u] > depth[v]) u = parent[u];
        while (depth[v] > depth[u]) v = parent[v];
        while (u !== v) {
            u = parent[u];
            v = parent[v];
        }
        return u;
    }
    for (let i = 0; i < q; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        console.log(lca(u, v));
    }
}

main();
