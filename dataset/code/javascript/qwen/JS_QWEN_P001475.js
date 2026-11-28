const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let l = 0, mid = 0, r = n - 1;
        while (mid <= r) {
            if (nums[mid] === 0) {
                [nums[l], nums[mid]] = [nums[mid], nums[l]];
                l++; mid++;
            } else if (nums[mid] === 1) {
                mid++;
            } else {
                [nums[mid], nums[r]] = [nums[r], nums[mid]];
                r--;
            }
        }
        console.log(nums.join(" "));
        rl.close();
    }
});
