const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const A = lines[1].split(/\s+/).map(Number);
        const B = lines[2].split(/\s+/).map(Number);
        
        let sumA = A.reduce((a,b)=>a+b, 0);
        let maxGain = 0;
        for(let i=0; i<n; i++) {
            maxGain = Math.max(maxGain, B[i]-A[i]);
        }
        console.log(sumA+maxGain);
        rl.close();
    }
});
