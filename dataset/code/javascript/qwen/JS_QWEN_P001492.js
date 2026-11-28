const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k, x] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let l = 0, r = n - 1;
        while (r - l + 1 > k) {
            if (Math.abs(nums[l] - x) > Math.abs(nums[r] - x)) l++;
            else r--;
        }
        console.log(nums.slice(l, r + 1).join(" "));
        rl.close();
    }
});
