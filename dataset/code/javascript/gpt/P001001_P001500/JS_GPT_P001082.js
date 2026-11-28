// P001082 - Find Eulerian Path
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    let ptr = 2;
    const degree = new Array(n).fill(0);
    for (let i = 0; i < m; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        degree[u]++;
        degree[v]++;
    }
    let odd = 0;
    for (let i = 0; i < n; i++) {
        if (degree[i] % 2 !== 0) odd++;
    }
    if (odd === 0 || odd === 2) {
        console.log("YES");
    } else {
        console.log("NO");
    }
}

main();
