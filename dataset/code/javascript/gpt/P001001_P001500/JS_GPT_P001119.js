// P001119 - Evaluate Division
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const adj = new Map();
    for (let i = 0; i < n; i++) {
        const u = input[ptr++];
        const v = input[ptr++];
        const val = parseFloat(input[ptr++]);
        if (!adj.has(u)) adj.set(u, []);
        if (!adj.has(v)) adj.set(v, []);
        adj.get(u).push({ to: v, w: val });
        adj.get(v).push({ to: u, w: 1.0 / val });
    }
    const q = parseInt(input[ptr++], 10);
    const out = [];
    function dfs(curr, target, visited) {
        if (curr === target) return 1.0;
        visited.add(curr);
        for (const edge of (adj.get(curr) || [])) {
            if (!visited.has(edge.to)) {
                const sub = dfs(edge.to, target, visited);
                if (sub !== -1.0) return edge.w * sub;
            }
        }
        return -1.0;
    }
    for (let i = 0; i < q; i++) {
        const u = input[ptr++];
        const v = input[ptr++];
        if (!adj.has(u) || !adj.has(v)) {
            out.push((-1.0).toFixed(5));
        } else {
            const res = dfs(u, v, new Set());
            out.push(res.toFixed(5));
        }
    }
    for (const val of out) console.log(val);
}

main();
