const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let pos = nums.filter(x => x > 0);
        let neg = nums.filter(x => x < 0);
        let res = [];
        let i = 0, j = 0;
        while (i < pos.length && j < neg.length) {
            res.push(pos[i++], neg[j++]);
        }
        console.log(res.join(" "));
        rl.close();
    }
});
