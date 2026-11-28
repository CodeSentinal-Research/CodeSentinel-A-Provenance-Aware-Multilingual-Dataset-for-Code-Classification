const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        const q = parseInt(lines[2]);
        let oddPrefix = [0];
        for (let x of arr) oddPrefix.push(oddPrefix[oddPrefix.length - 1] + (x % 2 !== 0 ? 1 : 0));
        let res = [];
        for (let i = 3; i < 3 + q; i++) {
            let [l, r] = lines[i].split(/\s+/).map(Number);
            res.push(oddPrefix[r + 1] - oddPrefix[l]);
        }
        console.log(res.join("\n"));
        rl.close();
    }
});
