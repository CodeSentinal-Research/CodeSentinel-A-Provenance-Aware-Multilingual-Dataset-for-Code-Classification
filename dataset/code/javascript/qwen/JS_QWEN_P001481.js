const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, limit] = lines[0].split(/\s+/).map(Number);
        const weights = lines[1].split(/\s+/).map(Number);
        
        weights.sort((a,b)=>a-b);
        let l = 0, r = n - 1, boats = 0;
        while (l <= r) {
            if (weights[l] + weights[r] <= limit) l++;
            r--;
            boats++;
        }
        console.log(boats);
        rl.close();
    }
});
