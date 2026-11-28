const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const ropes = lines[1].split(/\s+/).map(Number);
        
        let heap = [...ropes];
        // Min heap simulation
        heap.sort((a,b)=>a-b);
        
        let cost = 0;
        while(heap.length>1) {
            let r1 = heap.shift();
            let r2 = heap.shift();
            let sum = r1+r2;
            cost += sum;
            heap.push(sum);
            heap.sort((a,b)=>a-b);
        }
        console.log(cost);
        rl.close();
    }
});
