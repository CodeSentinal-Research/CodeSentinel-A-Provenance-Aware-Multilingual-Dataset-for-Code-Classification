// P001100 - Dynamic Connectivity Queries
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const q = parseInt(input[1], 10);
    let ptr = 2;
    const parent = Array.from({ length: n }, (_, i) => i);
    function find(i) {
        if (parent[i] === i) return i;
        return parent[i] = find(parent[i]);
    }
    for (let i = 0; i < q; i++) {
        const type = parseInt(input[ptr++], 10);
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        if (type === 1) {
            const ru = find(u), rv = find(v);
            if (ru !== rv) parent[ru] = rv;
        } else {
            console.log(find(u) === find(v) ? "YES" : "NO");
        }
    }
}

main();
