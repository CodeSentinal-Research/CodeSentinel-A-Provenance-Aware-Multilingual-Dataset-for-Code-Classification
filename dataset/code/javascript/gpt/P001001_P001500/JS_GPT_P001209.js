// P001209 - Stone Game III
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
    const targetMask = (1 << n) - 1;
    const visited = Array.from({ length: 1 << n }, () => new Array(n).fill(false));
    const queue = [];
    for (let i = 0; i < n; i++) {
        queue.push({ u: i, mask: 1 << i, dist: 0 });
        visited[1 << i][i] = true;
    }
    while (queue.length > 0) {
        const { u, mask, dist } = queue.shift();
        if (mask === targetMask) {
            console.log(dist);
            return;
        }
        for (const v of adj[u]) {
            const nextMask = mask | (1 << v);
            if (!visited[nextMask][v]) {
                visited[nextMask][v] = true;
                queue.push({ u: v, mask: nextMask, dist: dist + 1 });
            }
        }
    }
    console.log(0);
}

main();
