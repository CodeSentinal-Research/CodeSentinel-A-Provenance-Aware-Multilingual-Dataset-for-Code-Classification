const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 9) {
        let board = lines.map(l => l.split(/\s+/).map(Number));
        
        function isValid(r, c, num) {
            for(let i=0; i<9; i++) {
                if(board[r][i]===num || board[i][c]===num) return false;
                let br = 3*Math.floor(r/3)+Math.floor(i/3);
                let bc = 3*Math.floor(c/3)+i%3;
                if(board[br][bc]===num) return false;
            }
            return true;
        }
        
        function solve() {
            for(let r=0; r<9; r++) {
                for(let c=0; c<9; c++) {
                    if(board[r][c]===0) {
                        for(let num=1; num<=9; num++) {
                            if(isValid(r,c,num)) {
                                board[r][c] = num;
                                if(solve()) return true;
                                board[r][c] = 0;
                            }
                        }
                        return false;
                    }
                }
            }
            return true;
        }
        
        solve();
        board.forEach(row => console.log(row.join(" ")));
        rl.close();
    }
});
