// P001304 - Minimum Cost to Cut a Board
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const m = parseInt(input[0], 10);
    const n = parseInt(input[1], 10);
    let ptr = 2;
    const x = [];
    for (let i = 0; i < m - 1; i++) x.push(parseInt(input[ptr++], 10));
    const y = [];
    for (let i = 0; i < n - 1; i++) y.push(parseInt(input[ptr++], 10));
    x.sort((a, b) => b - a);
    y.sort((a, b) => b - a);
    let hPieces = 1, vPieces = 1, cost = 0, i = 0, j = 0;
    while (i < x.length && j < y.length) {
        if (x[i] >= y[j]) {
            cost += x[i] * vPieces;
            hPieces++;
            i++;
        } else {
            cost += y[j] * hPieces;
            vPieces++;
            j++;
        }
    }
    while (i < x.length) cost += x[i++] * vPieces;
    while (j < y.length) cost += y[j++] * hPieces;
    console.log(cost);
}

main();
