const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let l = 0, r = Math.max(...nums);
        while (l < r) {
            let mid = Math.floor((l + r) / 2);
            let count = 0, i = 0;
            while (i < n) {
                if (nums[i] <= mid) { count++; i += 2; }
                else i++;
            }
            if (count >= k) r = mid;
            else l = mid + 1;
        }
        console.log(l);
        rl.close();
    }
});
