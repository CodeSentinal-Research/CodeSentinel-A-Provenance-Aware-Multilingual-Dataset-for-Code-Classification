const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [n, index, maxSum] = line.split(/\s+/).map(Number);
        
        let l = 1, r = maxSum;
        while (l < r) {
            let mid = Math.ceil((l + r) / 2);
            let sum = mid;
            let left = Math.min(index, mid - 1);
            let right = Math.min(n - 1 - index, mid - 1);
            
            sum += (mid * (mid - 1) / 2) - ((mid - 1 - left) * (mid - left) / 2);
            sum += (mid * (mid - 1) / 2) - ((mid - 1 - right) * (mid - right) / 2);
            
            if (sum <= maxSum) l = mid;
            else r = mid - 1;
        }
        console.log(l);
        rl.close();
    }
});
