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
        // Heapify down for Min Heap
        let i = 0;
        while (true) {
            let l = 2 * i + 1, r = 2 * i + 2, minIdx = i;
            if (l < n && arr[l] < arr[minIdx]) minIdx = l;
            if (r < n && arr[r] < arr[minIdx]) minIdx = r;
            if (minIdx !== i) {
                [arr[i], arr[minIdx]] = [arr[minIdx], arr[i]];
                i = minIdx;
            } else break;
        }
        console.log(arr.join(" "));
        rl.close();
    }
});
