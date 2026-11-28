// P001110 - M-Coloring Problem
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    const maxColors = parseInt(input[2], 10);
    let ptr = 3;
    const adj = Array.from({ length: n }, () => []);
    for (let i = 0; i < m; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        adj[u].push(v);
        adj[v].push(u);
    }
    const color = new Array(n).fill(0);
    function isSafe(node, c) {
        for (const neighbor of adj[node]) {
            if (color[neighbor] === c) return false;
        }
        return true;
    }
    function solve(node) {
        if (node === n) return true;
        for (let c = 1; c <= maxColors; c++) {
            if (isSafe(node, c)) {
                color[node] = c;
                if (solve(node + 1)) return true;
                color[node] = 0;
            }
        }
        return false;
    }
    console.log(solve(0) ? "YES" : "NO");
}

main();
