const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let res = new Array(n);
        let l = 0, r = n - 1;
        for (let i = n - 1; i >= 0; i--) {
            if (Math.abs(nums[l]) > Math.abs(nums[r])) {
                res[i] = nums[l] * nums[l];
                l++;
            } else {
                res[i] = nums[r] * nums[r];
                r--;
            }
        }
        console.log(res.join(" "));
        rl.close();
    }
});
