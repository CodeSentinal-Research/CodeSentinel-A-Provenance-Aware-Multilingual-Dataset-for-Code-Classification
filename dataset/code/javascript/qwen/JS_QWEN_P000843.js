const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, p] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number).sort((a,b)=>a-b);
        
        let l = 0, r = nums[n-1] - nums[0];
        while (l < r) {
            let mid = Math.floor((l + r) / 2);
            let count = 0, i = 1;
            while (i < n) {
                if (nums[i] - nums[i-1] <= mid) { count++; i += 2; }
                else i++;
            }
            if (count >= p) r = mid;
            else l = mid + 1;
        }
        console.log(l);
        rl.close();
    }
});
