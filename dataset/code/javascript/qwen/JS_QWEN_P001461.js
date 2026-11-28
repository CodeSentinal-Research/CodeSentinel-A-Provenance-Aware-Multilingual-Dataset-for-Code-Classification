const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, target] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let l = 0, r = n - 1;
        while (l < r) {
            if (nums[l] + nums[r] === target) { console.log(`${l} ${r}`); rl.close(); return; }
            else if (nums[l] + nums[r] < target) l++;
            else r--;
        }
        console.log("-1");
        rl.close();
    }
});
