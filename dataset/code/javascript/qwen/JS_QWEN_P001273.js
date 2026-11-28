const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const barcodes = lines[1].split(/\s+/).map(Number);
        
        let count = {};
        for(let b of barcodes) count[b]=(count[b]||0)+1;
        
        let heap = [];
        Object.keys(count).forEach(k => heap.push([parseInt(k), count[k]]));
        heap.sort((a,b)=>b[1]-a[1]);
        
        let res = [];
        while(heap.length) {
            let [b1, c1] = heap.shift();
            if(res.length && res[res.length-1]===b1) {
                if(heap.length===0) break;
                let [b2, c2] = heap.shift();
                res.push(b2); c2--;
                if(c2>0) heap.unshift([b2, c2]);
                heap.unshift([b1, c1]);
            } else {
                res.push(b1); c1--;
                if(c1>0) heap.unshift([b1, c1]);
            }
            heap.sort((a,b)=>b[1]-a[1]);
        }
        console.log(res.join(" "));
        rl.close();
    }
});
