const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 3) {
        const [r, c] = lines[0].split(/\s+/).map(Number);
        let grid = [];
        for(let i=1; i<=r; i++) grid.push(lines[i].split(''));
        const word = lines[r+1];
        
        let found = false;
        function solve(i, j, idx) {
            if(idx===word.length) { found=true; return; }
            if(i<0 || i>=r || j<0 || j>=c || grid[i][j]!==word[idx]) return;
            
            let temp = grid[i][j];
            grid[i][j] = '#';
            solve(i+1, j, idx+1);
            solve(i-1, j, idx+1);
            solve(i, j+1, idx+1);
            solve(i, j-1, idx+1);
            grid[i][j] = temp;
        }
        
        for(let i=0; i<r; i++) {
            for(let j=0; j<c; j++) {
                solve(i, j, 0);
                if(found) break;
            }
            if(found) break;
        }
        console.log(found ? "YES" : "NO");
        rl.close();
    }
});
