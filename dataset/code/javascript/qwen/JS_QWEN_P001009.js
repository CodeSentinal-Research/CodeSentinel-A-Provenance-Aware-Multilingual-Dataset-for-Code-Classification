const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        // Swap root with last
        [arr[0], arr[n-1]] = [arr[n-1], arr[0]];
        arr.pop();
        // Heapify down
        let i = 0, len = arr.length;
        while (true) {
            let l = 2 * i + 1, r = 2 * i + 2, maxIdx = i;
            if (l < len && arr[l] > arr[maxIdx]) maxIdx = l;
            if (r < len && arr[r] > arr[maxIdx]) maxIdx = r;
            if (maxIdx !== i) {
                [arr[i], arr[maxIdx]] = [arr[maxIdx], arr[i]];
                i = maxIdx;
            } else break;
        }
        console.log(arr.join(" "));
        rl.close();
    }
});
