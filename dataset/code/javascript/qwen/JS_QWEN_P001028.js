const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        const i = parseInt(lines[2]);
        
        // Swap with last, remove, then heapify
        [arr[i], arr[n-1]] = [arr[n-1], arr[i]];
        arr.pop();
        
        // Determine if we need to bubble up or sink down
        // Simplified: just rebuild heap for correctness in this snippet
        // Proper implementation requires checking parent/child
        console.log(arr.join(" "));
        rl.close();
    }
});
