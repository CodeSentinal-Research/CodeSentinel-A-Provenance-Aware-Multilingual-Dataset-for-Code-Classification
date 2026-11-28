const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0].split(' ')[0])+1) {
        const [r, c] = lines[0].split(/\s+/).map(Number);
        let mat = [];
        for(let i=1; i<=r; i++) mat.push(lines[i].split(/\s+/).map(Number));
        let maxSum = -Infinity;
        for(let i=0; i<=r-3; i++) {
            for(let j=0; j<=c-3; j++) {
                let sum = mat[i][j]+mat[i][j+1]+mat[i][j+2] + mat[i+1][j+1] + mat[i+2][j]+mat[i+2][j+1]+mat[i+2][j+2];
                maxSum = Math.max(maxSum, sum);
            }
        }
        console.log(maxSum);
        rl.close();
    }
});
