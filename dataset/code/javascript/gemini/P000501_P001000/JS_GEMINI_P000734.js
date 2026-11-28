const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 3 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10), sr = parseInt(tokens[1], 10), sc = parseInt(tokens[2], 10);
        const board = Array.from({length: n}, () => Array(n).fill(-1));
        const dr = [-2, -1, 1, 2, 2, 1, -1, -2];
        const dc = [1, 2, 2, 1, -1, -2, -2, -1];
        board[sr][sc] = 0;
        function backtrack(r, c, step) {
            if (step === n * n) return true;
            for (let i = 0; i < 8; i++) {
                const nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && board[nr][nc] === -1) {
                    board[nr][nc] = step;
                    if (backtrack(nr, nc, step + 1)) return true;
                    board[nr][nc] = -1;
                }
            }
            return false;
        }
        if (backtrack(sr, sc, 1)) {
            for (const row of board) console.log(row.join(' '));
        } else {
            console.log(-1);
        }
    }
}
main();