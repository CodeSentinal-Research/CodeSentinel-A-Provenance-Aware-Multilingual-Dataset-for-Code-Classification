const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        const k = parseInt(lines[2]);
        let sum = nums.reduce((a,b)=>a+b, 0);
        if (sum % k !== 0) { console.log("false"); rl.close(); return; }
        let target = sum / k;
        nums.sort((a,b)=>b-a);
        let buckets = new Array(k).fill(0);
        function dfs(idx) {
            if (idx === n) return true;
            for (let i = 0; i < k; i++) {
                if (buckets[i] + nums[idx] <= target) {
                    buckets[i] += nums[idx];
                    if (dfs(idx + 1)) return true;
                    buckets[i] -= nums[idx];
                }
                if (buckets[i] === 0) break;
            }
            return false;
        }
        console.log(dfs(0) ? "true" : "false");
        rl.close();
    }
});
