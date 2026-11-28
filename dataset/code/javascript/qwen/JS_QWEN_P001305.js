const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const freqs = lines[1].split(/\s+/).map(Number);
        
        let heap = [...freqs];
        // Min heap simulation
        heap.sort((a,b)=>a-b);
        
        let cost = 0;
        while(heap.length > 1) {
            let f1 = heap.shift();
            let f2 = heap.shift();
            let sum = f1 + f2;
            cost += sum;
            heap.push(sum);
            heap.sort((a,b)=>a-b);
        }
        console.log(cost);
        rl.close();
    }
});
