// P001068 - Topological Sorting
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    let ptr = 2;
    const inDegree = new Array(n).fill(0);
    const adj = Array.from({ length: n }, () => []);
    for (let i = 0; i < m; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        adj[u].push(v);
        inDegree[v]++;
    }
    const queue = [];
    for (let i = 0; i < n; i++) {
        if (inDegree[i] === 0) queue.push(i);
    }
    const order = [];
    while (queue.length > 0) {
        queue.sort((a, b) => a - b);
        const u = queue.shift();
        order.push(u);
        for (const v of adj[u]) {
            inDegree[v]--;
            if (inDegree[v] === 0) queue.push(v);
        }
    }
    console.log(order.join(" "));
}

main();
