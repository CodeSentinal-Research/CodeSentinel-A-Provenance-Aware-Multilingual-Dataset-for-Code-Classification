// P001317 - Knight's Tour
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim();
    if (!input) return;
    const n = parseInt(input, 10);
    const board = Array.from({ length: n }, () => new Array(n).fill(-1));
    board[0][0] = 0;
    const moves = [[2,1],[1,2],[-1,2],[-2,1],[-2,-1],[-1,-2],[1,-2],[2,-1]];
    function solve(r, c, step) {
        if (step === n * n) return true;
        for (const [dr, dc] of moves) {
            const nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && board[nr][nc] === -1) {
                board[nr][nc] = step;
                if (solve(nr, nc, step + 1)) return true;
                board[nr][nc] = -1;
            }
        }
        return false;
    }
    if (solve(0, 0, 1)) {
        for (let i = 0; i < n; i++) console.log(board[i].join(" "));
    } else {
        console.log("-1");
    }
}

main();
