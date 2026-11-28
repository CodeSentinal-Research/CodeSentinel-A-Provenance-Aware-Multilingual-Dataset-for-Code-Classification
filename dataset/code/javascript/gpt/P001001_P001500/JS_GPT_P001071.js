// P001071 - Find the Mother Vertex
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
    }
    const visited = new Array(n).fill(false);
    let lastV = 0;
    function dfs(u) {
        visited[u] = true;
        for (const v of adj[u]) {
            if (!visited[v]) dfs(v);
        }
    }
    for (let i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            lastV = i;
        }
    }
    visited.fill(false);
    dfs(lastV);
    for (let i = 0; i < n; i++) {
        if (!visited[i]) {
            console.log("-1");
            return;
        }
    }
    console.log(lastV);
}

main();
