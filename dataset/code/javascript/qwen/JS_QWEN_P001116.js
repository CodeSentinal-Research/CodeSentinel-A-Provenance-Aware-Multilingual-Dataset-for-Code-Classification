const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [r, c] = lines[0].split(/\s+/).map(Number);
        let grid = [];
        for(let i=1; i<=r; i++) grid.push(lines[i].split(''));
        
        // Mark 'O's connected to boundary
        let queue = [];
        for(let i=0; i<r; i++) {
            for(let j=0; j<c; j++) {
                if((i===0 || i===r-1 || j===0 || j===c-1) && grid[i][j]==='O') {
                    queue.push([i, j]);
                    grid[i][j] = 'S'; // Safe
                }
            }
        }
        let dirs = [[0,1],[0,-1],[1,0],[-1,0]];
        while(queue.length > 0) {
            let [i, j] = queue.shift();
            for(let [di, dj] of dirs) {
                let ni = i+di, nj = j+dj;
                if(ni>=0 && ni<r && nj>=0 && nj<c && grid[ni][nj]==='O') {
                    grid[ni][nj] = 'S';
                    queue.push([ni, nj]);
                }
            }
        }
        // Flip remaining 'O' to 'X'
        for(let i=0; i<r; i++) {
            for(let j=0; j<c; j++) {
                if(grid[i][j]==='O') grid[i][j] = 'X';
                else if(grid[i][j]==='S') grid[i][j] = 'O';
            }
        }
        grid.forEach(row => console.log(row.join('')));
        rl.close();
    }
});
