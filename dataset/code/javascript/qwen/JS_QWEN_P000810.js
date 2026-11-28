const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, target] = lines[0].split(/\s+/).map(Number);
        const arr = lines[1].split(/\s+/).map(Number);
        let l = 0, r = n;
        while (l < r) {
            let m = Math.floor((l + r) / 2);
            if (arr[m] < target) l = m + 1;
            else r = m;
        }
        console.log(l);
        rl.close();
    }
});
