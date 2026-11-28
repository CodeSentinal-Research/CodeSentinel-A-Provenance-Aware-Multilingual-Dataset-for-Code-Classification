// P001109 - Graph Coloring Verification
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    let ptr = 2;
    const edges = [];
    for (let i = 0; i < m; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        edges.push([u, v]);
    }
    const colors = [];
    for (let i = 0; i < n; i++) {
        colors.push(parseInt(input[ptr++], 10));
    }
    for (const [u, v] of edges) {
        if (colors[u] === colors[v]) {
            console.log("INVALID");
            return;
        }
    }
    console.log("VALID");
}

main();
