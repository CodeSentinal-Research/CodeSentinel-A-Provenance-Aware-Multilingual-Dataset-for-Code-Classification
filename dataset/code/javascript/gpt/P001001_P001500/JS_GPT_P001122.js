// P001122 - Eventual Safe States
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
    const color = new Array(n).fill(0);
    function dfs(u) {
        if (color[u] > 0) return color[u] === 2;
        color[u] = 1;
        for (const v of adj[u]) {
            if (color[v] === 2) continue;
            if (color[v] === 1 || !dfs(v)) return false;
        }
        color[u] = 2;
        return true;
    }
    const safe = [];
    for (let i = 0; i < n; i++) {
        if (dfs(i)) safe.push(i);
    }
    console.log(safe.join(" "));
}

main();
