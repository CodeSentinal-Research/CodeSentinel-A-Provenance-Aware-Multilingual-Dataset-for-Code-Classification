const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        let A = [];
        for(let i=1; i<=n; i++) A.push(lines[i].split(/\s+/).map(Number));
        
        let res = Array(m).fill(0).map(() => Array(n).fill(0));
        for(let i=0; i<n; i++) {
            for(let j=0; j<m; j++) {
                res[j][i] = A[i][j];
            }
        }
        res.forEach(row => console.log(row.join(" ")));
        rl.close();
    }
});
