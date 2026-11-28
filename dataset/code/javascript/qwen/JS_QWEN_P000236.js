const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+1) {
        const n = parseInt(lines[0]);
        let mat = [];
        for(let i=1; i<=n; i++) mat.push(lines[i].split(/\s+/).map(Number));
        let maxDiff = -Infinity;
        let maxVal = mat[n-1][n-1];
        for(let i=n-2; i>=0; i--) {
            for(let j=n-2; j>=0; j--) {
                maxVal = Math.max(maxVal, mat[i+1][j], mat[i][j+1]);
                maxDiff = Math.max(maxDiff, maxVal - mat[i][j]);
            }
        }
        console.log(maxDiff);
        rl.close();
    }
});
