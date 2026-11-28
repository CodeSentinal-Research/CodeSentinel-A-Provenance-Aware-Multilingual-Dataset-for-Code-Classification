const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, x] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let prefix = 0;
        let res = -1;
        for (let i = 0; i < n; i++) {
            prefix += nums[i];
            if (prefix >= x) {
                res = i;
                break;
            }
        }
        
        console.log(res);
        rl.close();
    }
});
