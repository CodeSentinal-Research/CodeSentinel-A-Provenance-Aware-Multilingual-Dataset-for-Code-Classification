const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        let A = [];
        for(let i=1; i<=n; i++) A.push(lines[i].split(/\s+/).map(Number));
        
        // Transpose
        for(let i=0; i<n; i++) {
            for(let j=i; j<n; j++) {
                [A[i][j], A[j][i]] = [A[j][i], A[i][j]];
            }
        }
        // Reverse rows
        A.forEach(row => row.reverse());
        A.forEach(row => console.log(row.join(" ")));
        rl.close();
    }
});
