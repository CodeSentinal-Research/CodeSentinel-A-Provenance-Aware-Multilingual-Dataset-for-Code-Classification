// P001434 - Find Winner on a Tic-Tac-Toe Game
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const rows = [0, 0, 0], cols = [0, 0, 0];
    let diag = 0, antiDiag = 0;
    for (let i = 0; i < n; i++) {
        const r = parseInt(input[ptr++], 10);
        const c = parseInt(input[ptr++], 10);
        const player = (i % 2 === 0) ? 1 : -1;
        rows[r] += player;
        cols[c] += player;
        if (r === c) diag += player;
        if (r + c === 2) antiDiag += player;
        if (Math.abs(rows[r]) === 3 || Math.abs(cols[c]) === 3 || Math.abs(diag) === 3 || Math.abs(antiDiag) === 3) {
            console.log(player === 1 ? "A" : "B");
            return;
        }
    }
    console.log(n === 9 ? "Draw" : "Pending");
}

main();
