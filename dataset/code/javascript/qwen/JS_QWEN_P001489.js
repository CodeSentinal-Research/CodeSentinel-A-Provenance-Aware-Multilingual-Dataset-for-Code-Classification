const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, target] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        nums.sort((a,b)=>a-b);
        let res = 0;
        let mod = 10**9 + 7;
        for (let i = 0; i < n; i++) {
            if (nums[i] * 2 > target) break;
            let l = i + 1, r = n - 1, idx = -1;
            while (l <= r) {
                let m = Math.floor((l + r) / 2);
                if (nums[i] + nums[m] <= target) {
                    idx = m; l = m + 1;
                } else r = m - 1;
            }
            if (idx !== -1) {
                let count = idx - i;
                res = (res + Math.pow(2, count) - 1) % mod;
            }
        }
        console.log(res);
        rl.close();
    }
});
