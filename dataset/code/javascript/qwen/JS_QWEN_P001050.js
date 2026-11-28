const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        for (let i = Math.floor(n / 2) - 1; i >= 0; i--) {
            let idx = i;
            while (true) {
                let l = 2 * idx + 1, r = 2 * idx + 2, minIdx = idx;
                if (l < n && arr[l] < arr[minIdx]) minIdx = l;
                if (r < n && arr[r] < arr[minIdx]) minIdx = r;
                if (minIdx !== idx) {
                    [arr[idx], arr[minIdx]] = [arr[minIdx], arr[idx]];
                    idx = minIdx;
                } else break;
            }
        }
        console.log(arr.join(" "));
        rl.close();
    }
});
