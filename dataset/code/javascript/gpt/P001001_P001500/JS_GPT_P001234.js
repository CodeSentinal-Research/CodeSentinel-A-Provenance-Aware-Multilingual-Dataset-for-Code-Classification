// P001234 - Minimum Number of Platforms
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    let ptr = 2;
    const g = [];
    for (let i = 0; i < n; i++) g.push(parseInt(input[ptr++], 10));
    const s = [];
    for (let i = 0; i < m; i++) s.push(parseInt(input[ptr++], 10));
    g.sort((a, b) => a - b);
    s.sort((a, b) => a - b);
    let i = 0, j = 0;
    while (i < n && j < m) {
        if (s[j] >= g[i]) {
            i++;
        }
        j++;
    }
    console.log(i);
}

main();
