const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 3) {
        const [n, m, p] = lines[0].split(/\s+/).map(Number);
        let A = [], B = [];
        for(let i=1; i<=n; i++) A.push(lines[i].split(/\s+/).map(Number));
        for(let i=n+1; i<=n+m; i++) B.push(lines[i].split(/\s+/).map(Number));
        
        let res = Array(n).fill(0).map(() => Array(p).fill(0));
        for(let i=0; i<n; i++) {
            for(let j=0; j<p; j++) {
                for(let k=0; k<m; k++) {
                    res[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        res.forEach(row => console.log(row.join(" ")));
        rl.close();
    }
});
