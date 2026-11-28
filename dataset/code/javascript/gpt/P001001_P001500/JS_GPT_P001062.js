// P001062 - Count Vertices with Zero In-Degree
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    const inDegree = new Array(n).fill(0);
    let ptr = 2;
    for (let i = 0; i < m; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        inDegree[v]++;
    }
    let count = 0;
    for (let i = 0; i < n; i++) {
        if (inDegree[i] === 0) count++;
    }
    console.log(count);
}

main();
