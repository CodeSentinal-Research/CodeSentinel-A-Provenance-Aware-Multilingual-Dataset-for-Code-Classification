const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const [n, sr, sc] = lines[0].split(/\s+/).map(Number);
        let board = Array.from({length: n}, ()=>Array(n).fill(-1));
        let moves = [[2,1],[1,2],[-1,2],[-2,1],[-2,-1],[-1,-2],[1,-2],[2,-1]];
        
        function solve(r, c, moveNum) {
            if (moveNum === n*n) return true;
            for (let [dr, dc] of moves) {
                let nr = r+dr, nc = c+dc;
                if (nr>=0 && nr<n && nc>=0 && nc<n && board[nr][nc]===-1) {
                    board[nr][nc] = moveNum;
                    if (solve(nr, nc, moveNum+1)) return true;
                    board[nr][nc] = -1;
                }
            }
            return false;
        }
        board[sr][sc] = 0;
        if (solve(sr, sc, 1)) {
            board.forEach(row => console.log(row.join(" ")));
        } else {
            console.log(-1);
        }
        rl.close();
    }
});
