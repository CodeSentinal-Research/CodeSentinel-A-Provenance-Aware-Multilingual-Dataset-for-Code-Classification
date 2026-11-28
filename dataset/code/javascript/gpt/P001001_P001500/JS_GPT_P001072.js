// P001072 - Strongly Connected Components Count
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    let ptr = 2;
    const adj = Array.from({ length: n }, () => []);
    const radj = Array.from({ length: n }, () => []);
    for (let i = 0; i < m; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        adj[u].push(v);
        radj[v].push(u);
    }
    const visited = new Array(n).fill(false);
    const order = [];
    function dfs1(u) {
        visited[u] = true;
        for (const v of adj[u]) {
            if (!visited[v]) dfs1(v);
        }
        order.push(u);
    }
    for (let i = 0; i < n; i++) {
        if (!visited[i]) dfs1(i);
    }
    visited.fill(false);
    function dfs2(u) {
        visited[u] = true;
        for (const v of radj[u]) {
            if (!visited[v]) dfs2(v);
        }
    }
    let sccCount = 0;
    while (order.length > 0) {
        const u = order.pop();
        if (!visited[u]) {
            dfs2(u);
            sccCount++;
        }
    }
    console.log(sccCount);
}

main();
