// P001244 - Reorganize String
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    let ptr = 2;
    const A = [];
    for (let i = 0; i < n; i++) A.push([parseInt(input[ptr++], 10), parseInt(input[ptr++], 10)]);
    const B = [];
    for (let i = 0; i < m; i++) B.push([parseInt(input[ptr++], 10), parseInt(input[ptr++], 10)]);
    let i = 0, j = 0;
    const res = [];
    while (i < n && j < m) {
        const lo = Math.max(A[i][0], B[j][0]);
        const hi = Math.min(A[i][1], B[j][1]);
        if (lo <= hi) res.push([lo, hi]);
        if (A[i][1] < B[j][1]) i++;
        else j++;
    }
    for (const [s, e] of res) console.log(s + " " + e);
}

main();
