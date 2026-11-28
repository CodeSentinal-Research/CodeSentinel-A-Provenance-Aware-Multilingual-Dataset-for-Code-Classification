const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        if(n===1) { console.log(nums[0]); rl.close(); return; }
        let rob1 = (i, end) => {
            let prev2=0, prev1=0;
            for(let j=i; j<=end; j++) {
                let temp = prev1;
                prev1 = Math.max(prev1, prev2+nums[j]);
                prev2 = temp;
            }
            return prev1;
        };
        console.log(Math.max(rob1(0, n-2), rob1(1, n-1)));
        rl.close();
    }
});
