// P001098 - Count Connected Components Using Union-Find
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    let ptr = 2;
    const parent = Array.from({ length: n }, (_, i) => i);
    function find(i) {
        if (parent[i] === i) return i;
        return parent[i] = find(parent[i]);
    }
    let components = n;
    for (let i = 0; i < m; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        const ru = find(u), rv = find(v);
        if (ru !== rv) {
            parent[ru] = rv;
            components--;
        }
    }
    console.log(components);
}

main();
