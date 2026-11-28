const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        const newVal = parseInt(lines[2]);
        arr[0] = newVal;
        // Heapify down
        let i = 0;
        while (true) {
            let l = 2 * i + 1, r = 2 * i + 2, maxIdx = i;
            if (l < n && arr[l] > arr[maxIdx]) maxIdx = l;
            if (r < n && arr[r] > arr[maxIdx]) maxIdx = r;
            if (maxIdx !== i) {
                [arr[i], arr[maxIdx]] = [arr[maxIdx], arr[i]];
                i = maxIdx;
            } else break;
        }
        console.log(arr.join(" "));
        rl.close();
    }
});
