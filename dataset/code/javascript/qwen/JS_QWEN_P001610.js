const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let leftProd = new Array(n).fill(1);
        let rightProd = new Array(n).fill(1);
        
        for (let i = 1; i < n; i++) leftProd[i] = leftProd[i-1] * nums[i-1];
        for (let i = n - 2; i >= 0; i--) rightProd[i] = rightProd[i+1] * nums[i+1];
        
        let res = [];
        for (let i = 0; i < n; i++) res.push(leftProd[i] * rightProd[i]);
        console.log(res.join(" "));
        rl.close();
    }
});
