const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0].split(' ')[0])+2) {
        const [m, n] = lines[0].split(/\s+/).map(Number);
        let maze = [];
        for(let i=1; i<=m; i++) maze.push(lines[i].split(''));
        const [sr, sc] = lines[m+1].split(/\s+/).map(Number);
        let q = [[sr, sc, 0]];
        let visited = new Set([`${sr},${sc}`]);
        let dirs = [[0,1],[0,-1],[1,0],[-1,0]];
        while(q.length) {
            let [r,c,d] = q.shift();
            if((r===0 || r===m-1 || c===0 || c===n-1) && !(r===sr && c===sc)) {
                console.log(d); rl.close(); return;
            }
            for(let [dr,dc] of dirs) {
                let nr=r+dr, nc=c+dc;
                if(nr>=0 && nr<m && nc>=0 && nc<n && maze[nr][nc]==='.' && !visited.has(`${nr},${nc}`)) {
                    visited.add(`${nr},${nc}`);
                    q.push([nr,nc,d+1]);
                }
            }
        }
        console.log(-1);
        rl.close();
    }
});
