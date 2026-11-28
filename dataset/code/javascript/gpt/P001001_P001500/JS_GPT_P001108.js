// P001108 - Reachability Queries
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    const q = parseInt(input[2], 10);
    let ptr = 3;
    const adj = Array.from({ length: n }, () => []);
    for (let i = 0; i < m; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        adj[u].push(v);
    }
    function isReachable(s, d) {
        if (s === d) return true;
        const visited = new Array(n).fill(false);
        const queue = [s];
        visited[s] = true;
        while (queue.length > 0) {
            const u = queue.shift();
            if (u === d) return true;
            for (const v of adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    queue.push(v);
                }
            }
        }
        return false;
    }
    for (let i = 0; i < q; i++) {
        const s = parseInt(input[ptr++], 10);
        const d = parseInt(input[ptr++], 10);
        console.log(isReachable(s, d) ? "YES" : "NO");
    }
}

main();
