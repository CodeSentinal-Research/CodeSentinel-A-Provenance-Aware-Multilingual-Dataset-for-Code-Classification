// P001217 - Palindrome Partitioning II
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const r = parseInt(input[0], 10);
    const c = parseInt(input[1], 10);
    let ptr = 2;
    const grid = [];
    for (let i = 0; i < r; i++) {
        const row = [];
        for (let j = 0; j < c; j++) row.push(parseInt(input[ptr++], 10));
        grid.push(row);
    }
    const hor = Array.from({ length: r }, () => new Array(c).fill(0));
    const ver = Array.from({ length: r }, () => new Array(c).fill(0));
    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
            if (grid[i][j] === 1) {
                hor[i][j] = (j > 0 ? hor[i][j - 1] : 0) + 1;
                ver[i][j] = (i > 0 ? ver[i - 1][j] : 0) + 1;
            }
        }
    }
    let maxSide = 0;
    for (let i = r - 1; i >= 0; i--) {
        for (let j = c - 1; j >= 0; j--) {
            const limit = Math.min(hor[i][j], ver[i][j]);
            for (let side = limit; side > maxSide; side--) {
                if (ver[i][j - side + 1] >= side && hor[i - side + 1][j] >= side) {
                    maxSide = side;
                    break;
                }
            }
        }
    }
    console.log(maxSide * maxSide);
}

main();
