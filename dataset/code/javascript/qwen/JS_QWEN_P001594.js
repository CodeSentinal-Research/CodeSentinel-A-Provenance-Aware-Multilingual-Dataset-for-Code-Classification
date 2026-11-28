const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let prefix = [];
        let sum = 0;
        for (let num of nums) {
            sum += num;
            prefix.push(sum);
        }
        
        console.log(prefix.join(" "));
        rl.close();
    }
});
