const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let maxOdds = 0;
        let currOdds = 0;
        
        for (let i = 0; i < k; i++) {
            if (nums[i] % 2 !== 0) currOdds++;
        }
        
        maxOdds = currOdds;
        
        for (let i = k; i < n; i++) {
            if (nums[i] % 2 !== 0) currOdds++;
            if (nums[i - k] % 2 !== 0) currOdds--;
            maxOdds = Math.max(maxOdds, currOdds);
        }
        
        console.log(maxOdds);
        rl.close();
    }
});
