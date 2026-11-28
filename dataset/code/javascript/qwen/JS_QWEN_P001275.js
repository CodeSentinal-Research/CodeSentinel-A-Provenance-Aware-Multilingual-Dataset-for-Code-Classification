const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const quality = lines[1].split(/\s+/).map(Number);
        const wage = lines[2].split(/\s+/).map(Number);
        
        let workers = [];
        for(let i=0; i<n; i++) workers.push([wage[i]/quality[i], quality[i]]);
        workers.sort((a,b)=>a[0]-b[0]);
        
        let heap = [], sumQ=0, minCost=Infinity;
        for(let [ratio, q] of workers) {
            sumQ+=q;
            heap.push(q);
            heap.sort((a,b)=>b-a);
            if(heap.length>k) sumQ-=heap.shift();
            if(heap.length===k) minCost = Math.min(minCost, sumQ*ratio);
        }
        console.log(minCost.toFixed(5));
        rl.close();
    }
});
