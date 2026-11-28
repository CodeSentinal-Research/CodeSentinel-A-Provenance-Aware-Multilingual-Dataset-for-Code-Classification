const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let count = 0;
        let set = new Set();
        for (let i = 0; i < k; i++) set.add(nums[i]);
        if (set.size === k) count++;
        
        for (let i = k; i < n; i++) {
            set.add(nums[i]);
            set.delete(nums[i - k]);
            if (set.size === k) count++;
        }
        
        console.log(count);
        rl.close();
    }
});
