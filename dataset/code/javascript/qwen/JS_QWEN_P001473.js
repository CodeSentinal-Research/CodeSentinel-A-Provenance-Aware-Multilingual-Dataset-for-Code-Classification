const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, target] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        nums.sort((a,b)=>a-b);
        let closest = nums[0] + nums[1] + nums[2];
        for (let i = 0; i < n - 2; i++) {
            let l = i + 1, r = n - 1;
            while (l < r) {
                let sum = nums[i] + nums[l] + nums[r];
                if (Math.abs(sum - target) < Math.abs(closest - target)) closest = sum;
                if (sum < target) l++;
                else if (sum > target) r--;
                else { console.log(target); rl.close(); return; }
            }
        }
        console.log(closest);
        rl.close();
    }
});
