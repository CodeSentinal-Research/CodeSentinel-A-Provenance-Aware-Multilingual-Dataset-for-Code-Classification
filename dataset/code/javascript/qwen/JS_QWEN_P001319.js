const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 3) {
        const [r, c] = lines[0].split(/\s+/).map(Number);
        let grid = [];
        for(let i=1; i<=r; i++) grid.push(lines[i].split(''));
        const n = parseInt(lines[r+1]);
        let dict = [];
        for(let i=r+2; i<r+2+n; i++) dict.push(lines[i]);
        
        let res = new Set();
        // Trie would be better, but backtracking with set check is ok for small constraints
        function solve(i, j, word) {
            if(dict.includes(word)) res.add(word);
            if(i<0 || i>=r || j<0 || j>=c || grid[i][j]==='#') return;
            
            let temp = grid[i][j];
            grid[i][j] = '#';
            solve(i+1, j, word+temp);
            solve(i-1, j, word+temp);
            solve(i, j+1, word+temp);
            solve(i, j-1, word+temp);
            grid[i][j] = temp;
        }
        
        for(let i=0; i<r; i++) {
            for(let j=0; j<c; j++) {
                solve(i, j, "");
            }
        }
        console.log(Array.from(res).sort().join("\n"));
        rl.close();
    }
});
