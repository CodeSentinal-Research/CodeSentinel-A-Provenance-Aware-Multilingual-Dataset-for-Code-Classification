const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let res = [];
        function findInc(idx, curr) {
            if (curr.length >= 2) res.push(curr.slice());
            let used = new Set();
            for (let i = idx; i < n; i++) {
                if (used.has(nums[i])) continue;
                if (curr.length === 0 || nums[i] >= curr[curr.length - 1]) {
                    used.add(nums[i]);
                    curr.push(nums[i]);
                    findInc(i + 1, curr);
                    curr.pop();
                }
            }
        }
        findInc(0, []);
        console.log(res.map(r => r.join(" ")).join("\n"));
        rl.close();
    }
});
