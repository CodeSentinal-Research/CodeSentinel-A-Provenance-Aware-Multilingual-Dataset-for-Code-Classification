// P001198 - Count Square Submatrices with All Ones
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const r = parseInt(input[0], 10);
    const c = parseInt(input[1], 10);
    let ptr = 2;
    const matrix = [];
    for (let i = 0; i < r; i++) {
        const row = [];
        for (let j = 0; j < c; j++) row.push(parseInt(input[ptr++], 10));
        matrix.push(row);
    }
    let totalSquares = 0;
    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
            if (matrix[i][j] === 1 && i > 0 && j > 0) {
                matrix[i][j] = 1 + Math.min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]);
            }
            totalSquares += matrix[i][j];
        }
    }
    console.log(totalSquares);
}

main();
