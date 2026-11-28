// P001117 - Clone a Directed Graph
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
    for (let i = 0; i < n; i++) {
        adj[i].sort((a, b) => a - b);
        console.log(i + ": " + adj[i].join(" "));
    }
}

main();
