const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let maxNegs = 0;
        let currNegs = 0;
        
        for (let i = 0; i < k; i++) {
            if (nums[i] < 0) currNegs++;
        }
        
        maxNegs = currNegs;
        
        for (let i = k; i < n; i++) {
            if (nums[i] < 0) currNegs++;
            if (nums[i - k] < 0) currNegs--;
            maxNegs = Math.max(maxNegs, currNegs);
        }
        
        console.log(maxNegs);
        rl.close();
    }
});
