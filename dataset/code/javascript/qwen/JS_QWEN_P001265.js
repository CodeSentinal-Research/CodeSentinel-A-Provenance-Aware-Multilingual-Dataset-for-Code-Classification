const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const speed = lines[1].split(/\s+/).map(Number);
        const eff = lines[2].split(/\s+/).map(Number);
        
        let engineers = [];
        for(let i=0; i<n; i++) engineers.push([eff[i], speed[i]]);
        engineers.sort((a,b)=>b[0]-a[0]);
        
        let heap = [], sumSpeed=0, maxPerf=0;
        for(let [e, s] of engineers) {
            sumSpeed+=s;
            heap.push(s);
            heap.sort((a,b)=>a-b);
            if(heap.length>k) sumSpeed-=heap.shift();
            maxPerf = Math.max(maxPerf, sumSpeed*e);
        }
        console.log(maxPerf);
        rl.close();
    }
});
