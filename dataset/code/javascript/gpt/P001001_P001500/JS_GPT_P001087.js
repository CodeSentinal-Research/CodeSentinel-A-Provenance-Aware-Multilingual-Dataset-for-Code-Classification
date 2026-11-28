// P001087 - Check if an Undirected Graph is a Tree
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    if (m !== n - 1) {
        console.log("NO");
        return;
    }
    let ptr = 2;
    const parent = Array.from({ length: n }, (_, i) => i);
    function find(i) {
        if (parent[i] === i) return i;
        return parent[i] = find(parent[i]);
    }
    for (let i = 0; i < m; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        const ru = find(u), rv = find(v);
        if (ru === rv) {
            console.log("NO");
            return;
        }
        parent[ru] = rv;
    }
    console.log("YES");
}

main();
