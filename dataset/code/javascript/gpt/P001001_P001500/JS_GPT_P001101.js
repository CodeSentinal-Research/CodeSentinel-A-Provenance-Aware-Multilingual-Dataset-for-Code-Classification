// P001101 - Redundant Connection
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const parent = Array.from({ length: n + 1 }, (_, i) => i);
    function find(i) {
        if (parent[i] === i) return i;
        return parent[i] = find(parent[i]);
    }
    let ans = [];
    for (let i = 0; i < n; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        const ru = find(u), rv = find(v);
        if (ru === rv) {
            ans = [u, v];
        } else {
            parent[ru] = rv;
        }
    }
    console.log(ans.join(" "));
}

main();
