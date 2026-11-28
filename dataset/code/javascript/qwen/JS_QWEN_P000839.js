const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, threshold] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let l = 1, r = Math.max(...nums);
        while (l < r) {
            let mid = Math.floor((l + r) / 2);
            let sum = nums.reduce((acc, x) => acc + Math.ceil(x / mid), 0);
            if (sum > threshold) l = mid + 1;
            else r = mid;
        }
        console.log(l);
        rl.close();
    }
});
