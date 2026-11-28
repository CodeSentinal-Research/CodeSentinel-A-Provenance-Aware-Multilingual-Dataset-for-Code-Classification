// P001097 - Union-Find Operations
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
    function union(i, j) {
        const rootI = find(i);
        const rootJ = find(j);
        if (rootI !== rootJ) parent[rootI] = rootJ;
    }
    const out = [];
    for (let k = 0; k < q; k++) {
        const type = input[ptr++];
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        if (type === "union" || type === "1") {
            union(u, v);
        } else if (type === "find" || type === "2") {
            out.push(find(u) === find(v) ? "YES" : "NO");
        }
    }
    for (const res of out) console.log(res);
}

main();
