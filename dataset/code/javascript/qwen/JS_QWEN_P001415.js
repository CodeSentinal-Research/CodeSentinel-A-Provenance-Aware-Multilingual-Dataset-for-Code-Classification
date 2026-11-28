const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let set = new Set(nums);
        let count = 0;
        for (let x of set) {
            if (set.has(x + k)) count++;
        }
        console.log(count);
        rl.close();
    }
});
