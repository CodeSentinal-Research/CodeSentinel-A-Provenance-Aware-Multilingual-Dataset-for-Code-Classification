// P001348 - Fill the Matrix
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const q = parseInt(input[1], 10);
    let ptr = 2;
    const parent = Array.from({ length: 2 * n + 2 }, (_, i) => i);
    function find(i) {
        if (parent[i] === i) return i;
        return parent[i] = find(parent[i]);
    }
    function union(i, j) {
        const ri = find(i), rj = find(j);
        if (ri !== rj) parent[ri] = rj;
    }
    let possible = true;
    for (let k = 0; k < q; k++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        const c = parseInt(input[ptr++], 10);
        if (!possible) continue;
        if (c === 0) {
            if (find(u) === find(v + n) || find(u + n) === find(v)) {
                possible = false;
            } else {
                union(u, v);
                union(u + n, v + n);
            }
        } else {
            if (find(u) === find(v) || find(u + n) === find(v + n)) {
                possible = false;
            } else {
                union(u, v + n);
                union(u + n, v);
            }
        }
    }
    console.log(possible ? "YES" : "NO");
}

main();
