const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let set = new Set(nums);
        let res = -1;
        for (let x of set) {
            if (set.has(-x)) res = Math.max(res, Math.abs(x));
        }
        console.log(res);
        rl.close();
    }
});
