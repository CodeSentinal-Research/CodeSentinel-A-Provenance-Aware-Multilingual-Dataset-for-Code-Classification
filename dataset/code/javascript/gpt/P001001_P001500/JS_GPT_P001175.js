// P001175 - Falling Path Minimum Sum
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const matrix = [];
    for (let i = 0; i < n; i++) {
        const row = [];
        for (let j = 0; j < n; j++) row.push(parseInt(input[ptr++], 10));
        matrix.push(row);
    }
    for (let i = 1; i < n; i++) {
        for (let j = 0; j < n; j++) {
            let best = matrix[i - 1][j];
            if (j > 0) best = Math.min(best, matrix[i - 1][j - 1]);
            if (j < n - 1) best = Math.min(best, matrix[i - 1][j + 1]);
            matrix[i][j] += best;
        }
    }
    console.log(Math.min(...matrix[n - 1]));
}

main();
