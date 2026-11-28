const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0].split(' ')[0])+1) {
        const [r, c] = lines[0].split(/\s+/).map(Number);
        let mat = [];
        for(let i=1; i<=r; i++) mat.push(lines[i].split(/\s+/).map(Number));
        let maxOnes = -1, idx = -1;
        for(let i=0; i<r; i++) {
            let ones = 0;
            for(let j=0; j<c; j++) if(mat[i][j]===1) ones++;
            if(ones > maxOnes) { maxOnes = ones; idx = i; }
        }
        console.log(idx);
        rl.close();
    }
});
