const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        let res = new Set();
        for (let x of nums) {
            let cur = 0;
            res.add(cur | x);
            let nextRes = new Set(res);
            for (let val of res) {
                nextRes.add(val | x);
            }
            res = nextRes;
        }
        console.log(res.size);
        rl.close();
    }
});
