const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let l = Math.max(...nums), r = nums.reduce((a,b)=>a+b, 0);
        while (l < r) {
            let mid = Math.floor((l + r) / 2);
            let count = 1, curr = 0;
            for (let x of nums) {
                if (curr + x > mid) { count++; curr = x; }
                else curr += x;
            }
            if (count > m) l = mid + 1;
            else r = mid;
        }
        console.log(l);
        rl.close();
    }
});
