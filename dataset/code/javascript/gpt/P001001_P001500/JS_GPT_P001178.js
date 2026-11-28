// P001178 - Gold Mine Problem
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const r = parseInt(input[0], 10);
    const c = parseInt(input[1], 10);
    let ptr = 2;
    const mine = [];
    for (let i = 0; i < r; i++) {
        const row = [];
        for (let j = 0; j < c; j++) row.push(parseInt(input[ptr++], 10));
        mine.push(row);
    }
    for (let j = c - 2; j >= 0; j--) {
        for (let i = 0; i < r; i++) {
            let right = mine[i][j + 1];
            let rightUp = i > 0 ? mine[i - 1][j + 1] : 0;
            let rightDown = i < r - 1 ? mine[i + 1][j + 1] : 0;
            mine[i][j] += Math.max(right, rightUp, rightDown);
        }
    }
    let maxGold = 0;
    for (let i = 0; i < r; i++) maxGold = Math.max(maxGold, mine[i][0]);
    console.log(maxGold);
}

main();
