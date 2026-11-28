const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, m, target] = lines[0].split(/\s+/).map(Number);
        let matrix = [];
        for (let i = 1; i <= n; i++) matrix.push(lines[i].split(/\s+/).map(Number));
        
        let r = 0, c = m - 1;
        while (r < n && c >= 0) {
            if (matrix[r][c] === target) { console.log("true"); rl.close(); return; }
            else if (matrix[r][c] > target) c--;
            else r++;
        }
        console.log("false");
        rl.close();
    }
});
