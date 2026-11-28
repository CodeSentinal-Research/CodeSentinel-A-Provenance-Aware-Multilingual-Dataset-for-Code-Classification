const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const candies = lines[1].split(/\s+/).map(Number);
        
        let l = 0, r = Math.max(...candies);
        while (l < r) {
            let mid = Math.ceil((l + r) / 2);
            let count = 0;
            for (let c of candies) count += Math.floor(c / mid);
            if (count >= k) l = mid;
            else r = mid - 1;
        }
        console.log(l);
        rl.close();
    }
});
