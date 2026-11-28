const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const sticks = lines[1].split(/\s+/).map(Number);
        
        let heap = [...sticks];
        heap.sort((a,b)=>a-b);
        
        let cost = 0;
        while(heap.length > 1) {
            let s1 = heap.shift();
            let s2 = heap.shift();
            let sum = s1 + s2;
            cost += sum;
            heap.push(sum);
            heap.sort((a,b)=>a-b);
        }
        console.log(cost);
        rl.close();
    }
});
