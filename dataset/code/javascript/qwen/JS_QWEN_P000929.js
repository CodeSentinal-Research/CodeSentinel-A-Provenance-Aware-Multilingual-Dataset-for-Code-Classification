const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 3) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        let A = [], B = [];
        for(let i=1; i<=n; i++) A.push(lines[i].split(/\s+/).map(Number));
        for(let i=n+1; i<=2*n; i++) B.push(lines[i].split(/\s+/).map(Number));
        
        let res = [];
        for(let i=0; i<n; i++) {
            let row = [];
            for(let j=0; j<m; j++) row.push(A[i][j] + B[i][j]);
            res.push(row.join(" "));
        }
        console.log(res.join("\n"));
        rl.close();
    }
});
