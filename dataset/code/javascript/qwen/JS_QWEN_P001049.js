const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, q] = lines[0].split(/\s+/).map(Number);
        const arr = lines[1].split(/\s+/).map(Number);
        for(let i=2; i<2+q; i++) {
            const [idx, val] = lines[i].split(/\s+/).map(Number);
            arr[idx] = val;
            // Simple heapify for demo
        }
        console.log(arr.join(" "));
        rl.close();
    }
});
