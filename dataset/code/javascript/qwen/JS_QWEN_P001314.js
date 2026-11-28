const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 9) {
        let board = lines.map(l => l.split(/\s+/).map(Number));
        let valid = true;
        
        // Check rows and cols
        for(let i=0; i<9; i++) {
            let rSet = new Set(), cSet = new Set();
            for(let j=0; j<9; j++) {
                if(board[i][j]!==0) {
                    if(rSet.has(board[i][j])) valid=false;
                    rSet.add(board[i][j]);
                }
                if(board[j][i]!==0) {
                    if(cSet.has(board[j][i])) valid=false;
                    cSet.add(board[j][i]);
                }
            }
        }
        
        // Check boxes
        for(let r=0; r<9; r+=3) {
            for(let c=0; c<9; c+=3) {
                let bSet = new Set();
                for(let i=0; i<3; i++) {
                    for(let j=0; j<3; j++) {
                        let val = board[r+i][c+j];
                        if(val!==0) {
                            if(bSet.has(val)) valid=false;
                            bSet.add(val);
                        }
                    }
                }
            }
        }
        console.log(valid ? "YES" : "NO");
        rl.close();
    }
});
