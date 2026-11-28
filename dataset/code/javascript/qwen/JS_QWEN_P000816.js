const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let l = 0, r = n - 1;
        while (l < r) {
            let m = Math.floor((l + r) / 2);
            if (arr[m] > arr[m + 1]) r = m;
            else l = m + 1;
        }
        console.log(l);
        rl.close();
    }
});
