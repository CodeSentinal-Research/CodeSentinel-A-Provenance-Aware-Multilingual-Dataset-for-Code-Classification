const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [r, c] = lines[0].split(/\s+/).map(Number);
        let grid = [];
        for(let i=1; i<=r; i++) grid.push(lines[i].split(/\s+/).map(Number));
        
        let queue = [];
        let fresh = 0;
        for(let i=0; i<r; i++) {
            for(let j=0; j<c; j++) {
                if(grid[i][j]===2) queue.push([i, j, 0]);
                else if(grid[i][j]===1) fresh++;
            }
        }
        
        let time = 0;
        let dirs = [[0,1],[0,-1],[1,0],[-1,0]];
        while(queue.length > 0) {
            let [i, j, t] = queue.shift();
            time = t;
            for(let [di, dj] of dirs) {
                let ni = i+di, nj = j+dj;
                if(ni>=0 && ni<r && nj>=0 && nj<c && grid[ni][nj]===1) {
                    grid[ni][nj] = 2;
                    fresh--;
                    queue.push([ni, nj, t+1]);
                }
            }
        }
        console.log(fresh === 0 ? time : -1);
        rl.close();
    }
});
