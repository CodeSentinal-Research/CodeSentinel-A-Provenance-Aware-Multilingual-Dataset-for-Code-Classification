const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        let count=0, len=0;
        for(let i=2; i<n; i++) {
            if(nums[i]-nums[i-1] === nums[i-1]-nums[i-2]) {
                len++;
                count += len;
            } else {
                len = 0;
            }
        }
        console.log(count);
        rl.close();
    }
});
