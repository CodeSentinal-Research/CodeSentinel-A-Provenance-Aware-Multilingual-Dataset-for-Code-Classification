const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let res = [];
        let sum = 0;
        for (let x of arr) {
            sum += x;
            res.push(sum);
        }
        console.log(res.join(" "));
        rl.close();
    }
});
