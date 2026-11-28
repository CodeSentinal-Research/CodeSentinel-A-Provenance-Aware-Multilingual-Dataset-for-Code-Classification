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
        for(let i=0; i<r; i++) {
            let temp = new Array(c).fill(0);
            for(let j=i; j<r; j++) {
                for(let k=0; k<c; k++) temp[k]+=mat[j][k];
                // Kadane on temp
                let curr=0, maxK=-Infinity;
                for(let x of temp) { curr=Math.max(x, curr+x); maxK=Math.max(maxK, curr); }
                maxSum = Math.max(maxSum, maxK);
            }
        }
        console.log(maxSum);
        rl.close();
    }
});
