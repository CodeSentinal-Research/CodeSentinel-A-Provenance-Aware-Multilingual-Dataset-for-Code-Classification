const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        let inc = new Array(n).fill(1);
        let dec = new Array(n).fill(1);
        for(let i=1; i<n; i++) {
            for(let j=0; j<i; j++) {
                if(nums[i]>nums[j]) inc[i] = Math.max(inc[i], inc[j]+1);
            }
        }
        for(let i=n-2; i>=0; i--) {
            for(let j=n-1; j>i; j--) {
                if(nums[i]>nums[j]) dec[i] = Math.max(dec[i], dec[j]+1);
            }
        }
        let maxLen = 0;
        for(let i=0; i<n; i++) maxLen = Math.max(maxLen, inc[i]+dec[i]-1);
        console.log(maxLen);
        rl.close();
    }
});
