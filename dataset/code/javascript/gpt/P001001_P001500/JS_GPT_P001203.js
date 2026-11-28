// P001203 - Russian Doll Envelopes
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const grid = [];
    for (let i = 0; i < n; i++) {
        const row = [];
        for (let j = 0; j < n; j++) row.push(parseInt(input[ptr++], 10));
        grid.push(row);
    }
    let prev = [...grid[0]];
    for (let i = 1; i < n; i++) {
        const curr = new Array(n).fill(0);
        for (let j = 0; j < n; j++) {
            let minPrev = Infinity;
            for (let k = 0; k < n; k++) {
                if (k !== j && prev[k] < minPrev) minPrev = prev[k];
            }
            curr[j] = grid[i][j] + minPrev;
        }
        prev = curr;
    }
    console.log(Math.min(...prev));
}

main();
