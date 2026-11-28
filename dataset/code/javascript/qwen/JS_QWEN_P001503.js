const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let onesIndices = [];
        for (let i = 0; i < n; i++) {
            if (nums[i] === 1) onesIndices.push(i);
        }
        
        if (onesIndices.length < k) { console.log(-1); rl.close(); return; }
        
        let minOps = Infinity;
        let m = k;
        let medianIdx = Math.floor(m / 2);
        
        for (let i = 0; i <= onesIndices.length - m; i++) {
            let ops = 0;
            let median = onesIndices[i + medianIdx];
            for (let j = i; j < i + m; j++) {
                ops += Math.abs(onesIndices[j] - median) - Math.abs(j - i - medianIdx);
            }
            minOps = Math.min(minOps, ops);
        }
        
        console.log(minOps);
        rl.close();
    }
});
