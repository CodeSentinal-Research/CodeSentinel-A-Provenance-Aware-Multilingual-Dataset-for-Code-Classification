// P001154 - Matrix Chain Multiplication
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const p = [];
    for (let i = 0; i < n; i++) p.push(parseInt(input[1 + i], 10));
    const m = Array.from({ length: n }, () => new Array(n).fill(0));
    for (let len = 2; len < n; len++) {
        for (let i = 1; i < n - len + 1; i++) {
            const j = i + len - 1;
            m[i][j] = Infinity;
            for (let k = i; k < j; k++) {
                const q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) m[i][j] = q;
            }
        }
    }
    console.log(m[1][n - 1]);
}

main();
