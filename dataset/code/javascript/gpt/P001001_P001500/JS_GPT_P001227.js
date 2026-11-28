// P001227 - Count Derangements
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const r = parseInt(input[0], 10);
    const c = parseInt(input[1], 10);
    let ptr = 2;
    const mat = [];
    for (let i = 0; i < r; i++) {
        const row = [];
        for (let j = 0; j < c; j++) row.push(parseInt(input[ptr++], 10));
        mat.push(row);
    }
    const h = Array.from({ length: r }, () => new Array(c).fill(0));
    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
            if (mat[i][j] === 1) {
                h[i][j] = (j > 0 ? h[i][j - 1] : 0) + 1;
            }
        }
    }
    let total = 0;
    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
            let minW = Infinity;
            for (let k = i; k >= 0; k--) {
                minW = Math.min(minW, h[k][j]);
                if (minW === 0) break;
                total += minW;
            }
        }
    }
    console.log(total);
}

main();
