const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const weights = lines[1].split(/\s+/).map(Number);
        
        let cuts = [];
        for(let i=1; i<n; i++) cuts.push(weights[i-1]+weights[i]);
        cuts.sort((a,b)=>a-b);
        
        let minSum = cuts.slice(0, k-1).reduce((a,b)=>a+b, 0);
        let total = weights.reduce((a,b)=>a+b, 0);
        let maxSum = total - minSum;
        
        console.log(maxSum - (total - cuts.slice(n-k).reduce((a,b)=>a+b, 0))); // Simplified
        rl.close();
    }
});
