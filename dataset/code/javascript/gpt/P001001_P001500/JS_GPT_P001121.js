// P001121 - Minimum Height Trees
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    if (n === 1) {
        console.log(0);
        return;
    }
    let ptr = 1;
    const adj = Array.from({ length: n }, () => new Set());
    for (let i = 0; i < n - 1; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        adj[u].add(v);
        adj[v].add(u);
    }
    let leaves = [];
    for (let i = 0; i < n; i++) {
        if (adj[i].size === 1) leaves.push(i);
    }
    let remaining = n;
    while (remaining > 2) {
        remaining -= leaves.length;
        const newLeaves = [];
        for (const leaf of leaves) {
            const neighbor = adj[leaf].values().next().value;
            adj[neighbor].delete(leaf);
            if (adj[neighbor].size === 1) newLeaves.push(neighbor);
        }
        leaves = newLeaves;
    }
    leaves.sort((a, b) => a - b);
    console.log(leaves.join(" "));
}

main();
