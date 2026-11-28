const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let mod = 10**9+7;
        let heap = [...nums];
        heap.sort((a,b)=>a-b);
        
        for(let i=0; i<k; i++) {
            let min = heap.shift();
            min++;
            heap.push(min);
            heap.sort((a,b)=>a-b);
        }
        
        let prod = 1;
        for(let x of heap) prod = (prod*x)%mod;
        console.log(prod);
        rl.close();
    }
});
