const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        let A = [];
        for(let i=1; i<=n; i++) A.push(lines[i].split(/\s+/).map(Number));
        
        let sum = 0;
        for(let i=0; i<n; i++) {
            sum += A[i][i];
            if(i !== n-1-i) sum += A[i][n-1-i];
        }
        console.log(sum);
        rl.close();
    }
});
