const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 3 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10), m = parseInt(tokens[1], 10);
        const board = [];
        let idx = 2;
        for (let i = 0; i < n; i++) {
            board.push(tokens.slice(idx, idx + m));
            idx += m;
        }
        const word = tokens[idx];
        const dr = [1, -1, 0, 0], dc = [0, 0, 1, -1];
        function backtrack(r, c, k) {
            if (k === word.length) return true;
            if (r < 0 || r >= n || c < 0 || c >= m || board[r][c] !== word[k]) return false;
            const temp = board[r][c];
            board[r][c] = '#';
            for (let i = 0; i < 4; i++) {
                if (backtrack(r + dr[i], c + dc[i], k + 1)) return true;
            }
            board[r][c] = temp;
            return false;
        }
        let found = false;
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < m; j++) {
                if (backtrack(i, j, 0)) { found = true; break; }
            }
            if (found) break;
        }
        console.log(found ? "true" : "false");
    }
}
main();