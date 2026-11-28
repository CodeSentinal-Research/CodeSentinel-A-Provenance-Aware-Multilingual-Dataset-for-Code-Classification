const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0].split(' ')[0])+1) {
        const [m, n] = lines[0].split(/\s+/).map(Number);
        let grid = [];
        for(let i=1; i<=m; i++) grid.push(lines[i].split(/\s+/).map(Number));
        let q = [];
        let fresh = 0;
        for(let i=0; i<m; i++) {
            for(let j=0; j<n; j++) {
                if(grid[i][j]===2) q.push([i,j]);
                else if(grid[i][j]===1) fresh++;
            }
        }
        let mins = 0;
        let dirs = [[0,1],[0,-1],[1,0],[-1,0]];
        while(q.length && fresh>0) {
            let size = q.length;
            for(let k=0; k<size; k++) {
                let [r,c] = q.shift();
                for(let [dr,dc] of dirs) {
                    let nr=r+dr, nc=c+dc;
                    if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]===1) {
                        grid[nr][nc]=2;
                        fresh--;
                        q.push([nr,nc]);
                    }
                }
            }
            mins++;
        }
        console.log(fresh===0 ? mins : -1);
        rl.close();
    }
});
