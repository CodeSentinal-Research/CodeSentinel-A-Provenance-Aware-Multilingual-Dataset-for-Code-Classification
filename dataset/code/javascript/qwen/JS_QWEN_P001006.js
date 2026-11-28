const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let isMinHeap = true;
        for (let i = 0; i < n; i++) {
            let l = 2 * i + 1, r = 2 * i + 2;
            if (l < n && arr[l] < arr[i]) isMinHeap = false;
            if (r < n && arr[r] < arr[i]) isMinHeap = false;
        }
        console.log(isMinHeap ? "YES" : "NO");
        rl.close();
    }
});
