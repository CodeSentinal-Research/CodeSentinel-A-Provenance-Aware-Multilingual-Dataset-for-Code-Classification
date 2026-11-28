const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+1) {
        const n = parseInt(lines[0]);
        let board = [];
        for(let i=1; i<=n; i++) board.push(lines[i].split(/\s+/).map(Number));
        let target = n*n;
        let q = [[1, 0]];
        let visited = new Set([1]);
        while(q.length) {
            let [curr, moves] = q.shift();
            if(curr===target) { console.log(moves); rl.close(); return; }
            for(let i=1; i<=6; i++) {
                let next = curr+i;
                if(next > target) break;
                let r = Math.floor((next-1)/n), c = (next-1)%n;
                if(r%2!==0) c = n-1-c;
                let val = board[n-1-r][c];
                let dest = val===-1 ? next : val;
                if(!visited.has(dest)) {
                    visited.add(dest);
                    q.push([dest, moves+1]);
                }
            }
        }
        console.log(-1);
        rl.close();
    }
});
