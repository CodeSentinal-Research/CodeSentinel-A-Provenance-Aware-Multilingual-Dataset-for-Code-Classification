const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        for (let i = 0; i < n - 1; i++) {
            if (nums[i] === nums[i+1]) {
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }
        let res = nums.filter(x => x !== 0);
        while (res.length < n) res.push(0);
        console.log(res.join(" "));
        rl.close();
    }
});
