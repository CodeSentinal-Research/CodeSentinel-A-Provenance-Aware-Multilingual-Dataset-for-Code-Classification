const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, bricks, ladders] = lines[0].split(/\s+/).map(Number);
        const heights = lines[1].split(/\s+/).map(Number);
        
        let heap = [];
        for(let i=0; i<n-1; i++) {
            let diff = heights[i+1]-heights[i];
            if(diff>0) {
                heap.push(diff);
                heap.sort((a,b)=>a-b);
                if(heap.length>ladders) {
                    bricks-=heap.shift();
                    if(bricks<0) { console.log(i); rl.close(); return; }
                }
            }
        }
        console.log(n-1);
        rl.close();
    }
});
