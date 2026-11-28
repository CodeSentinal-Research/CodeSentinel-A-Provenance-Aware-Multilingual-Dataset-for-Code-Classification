const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        const val = parseInt(lines[2]);
        arr.push(val);
        let i = arr.length - 1;
        while (i > 0) {
            let p = Math.floor((i - 1) / 2);
            if (arr[p] > arr[i]) {
                [arr[p], arr[i]] = [arr[i], arr[p]];
                i = p;
            } else break;
        }
        console.log(arr.join(" "));
        rl.close();
    }
});
