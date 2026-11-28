const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        const i = parseInt(lines[2]);
        
        let idx = i;
        while (true) {
            let l = 2 * idx + 1, r = 2 * idx + 2, maxIdx = idx;
            if (l < n && arr[l] > arr[maxIdx]) maxIdx = l;
            if (r < n && arr[r] > arr[maxIdx]) maxIdx = r;
            if (maxIdx !== idx) {
                [arr[idx], arr[maxIdx]] = [arr[maxIdx], arr[idx]];
                idx = maxIdx;
            } else break;
        }
        console.log(arr.join(" "));
        rl.close();
    }
});
