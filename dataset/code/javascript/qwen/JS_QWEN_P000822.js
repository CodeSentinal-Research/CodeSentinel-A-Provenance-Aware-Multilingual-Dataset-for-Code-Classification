const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [n, k, xStr] = line.split(/\s+/).map(Number);
        const arr = lines[1].split(/\s+/).map(Number); // Wait, input is on next line?
        // Problem says: Input: Integer n, Sorted array, Integer k, Integer x.
        // Usually: Line 1: N K X, Line 2: Array
        // Let's assume Line 1 has N K X, Line 2 has Array
        const parts = lines[0].split(/\s+/);
        const N = parseInt(parts[0]);
        const K = parseInt(parts[1]);
        const X = parseInt(parts[2]);
        const arr = lines[1].split(/\s+/).map(Number);
        
        let l = 0, r = N - K;
        while (l < r) {
            let m = Math.floor((l + r) / 2);
            if (X - arr[m] > arr[m + K] - X) l = m + 1;
            else r = m;
        }
        console.log(arr.slice(l, l + K).join(" "));
        rl.close();
    }
});
