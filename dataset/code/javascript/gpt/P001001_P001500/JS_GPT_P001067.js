// P001067 - Count Reachable Vertices
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    const src = parseInt(input[2], 10);
    let ptr = 3;
    const adj = Array.from({ length: n }, () => []);
    for (let i = 0; i < m; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        adj[u].push(v);
    }
    const visited = new Array(n).fill(false);
    let count = 0;
    const queue = [src];
    visited[src] = true;
    while (queue.length > 0) {
        const u = queue.shift();
        count++;
        for (const v of adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                queue.push(v);
            }
        }
    }
    console.log(count);
}

main();
