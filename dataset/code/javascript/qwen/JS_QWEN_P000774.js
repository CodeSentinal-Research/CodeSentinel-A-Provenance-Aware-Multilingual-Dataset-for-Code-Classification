const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0]) + 2) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        let board = [];
        for (let i = 1; i <= n; i++) board.push(lines[i].split(''));
        const word = lines[n + 1];
        function search(r, c, idx) {
            if (idx === word.length) return true;
            if (r < 0 || r >= n || c < 0 || c >= m || board[r][c] !== word[idx]) return false;
            let temp = board[r][c];
            board[r][c] = '#';
            let found = search(r + 1, c, idx + 1) || search(r - 1, c, idx + 1) || search(r, c + 1, idx + 1) || search(r, c - 1, idx + 1);
            board[r][c] = temp;
            return found;
        }
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < m; j++) {
                if (search(i, j, 0)) { console.log("true"); rl.close(); return; }
            }
        }
        console.log("false");
        rl.close();
    }
});
