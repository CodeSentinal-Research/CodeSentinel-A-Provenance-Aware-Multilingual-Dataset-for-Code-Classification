const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let set = new Set(nums);
        for (let x of nums) {
            if (set.has(2 * x)) { console.log("YES"); rl.close(); return; }
        }
        console.log("NO");
        rl.close();
    }
});
