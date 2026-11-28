// P001314 - Validate Sudoku Solution
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 81) return;
    const board = [];
    let ptr = 0;
    for (let i = 0; i < 9; i++) {
        const row = [];
        for (let j = 0; j < 9; j++) row.push(parseInt(input[ptr++], 10));
        board.push(row);
    }
    for (let i = 0; i < 9; i++) {
        const rowSet = new Set(), colSet = new Set(), boxSet = new Set();
        for (let j = 0; j < 9; j++) {
            const rVal = board[i][j], cVal = board[j][i];
            const br = 3 * Math.floor(i / 3) + Math.floor(j / 3);
            const bc = 3 * (i % 3) + (j % 3);
            const bVal = board[br][bc];
            if (rVal < 1 || rVal > 9 || rowSet.has(rVal)) { console.log("INVALID"); return; }
            if (cVal < 1 || cVal > 9 || colSet.has(cVal)) { console.log("INVALID"); return; }
            if (bVal < 1 || bVal > 9 || boxSet.has(bVal)) { console.log("INVALID"); return; }
            rowSet.add(rVal); colSet.add(cVal); boxSet.add(bVal);
        }
    }
    console.log("VALID");
}

main();
