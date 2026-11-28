const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let l = 0, zeros = 0, maxLen = 0;
        for (let r = 0; r < n; r++) {
            if (nums[r] === 0) zeros++;
            while (zeros > k) {
                if (nums[l] === 0) zeros--;
                l++;
            }
            maxLen = Math.max(maxLen, r - l + 1);
        }
        console.log(maxLen);
        rl.close();
    }
});
