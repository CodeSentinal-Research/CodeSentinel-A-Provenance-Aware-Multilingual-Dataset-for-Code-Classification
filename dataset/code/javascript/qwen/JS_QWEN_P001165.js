const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        let maxProd = nums[0], minProd = nums[0], res = nums[0];
        for(let i=1; i<n; i++) {
            let tempMax = Math.max(nums[i], maxProd*nums[i], minProd*nums[i]);
            minProd = Math.min(nums[i], maxProd*nums[i], minProd*nums[i]);
            maxProd = tempMax;
            res = Math.max(res, maxProd);
        }
        console.log(res);
        rl.close();
    }
});
