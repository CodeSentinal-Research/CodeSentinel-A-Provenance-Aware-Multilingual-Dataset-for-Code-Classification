const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let count = {};
    for(let c of s) count[c]=(count[c]||0)+1;
    
    let heap = [];
    Object.keys(count).forEach(c => heap.push([c, count[c]]));
    heap.sort((a,b)=>b[1]-a[1]);
    
    let res = new Array(s.length);
    let idx = 0;
    while(heap.length) {
        let [c, f] = heap.shift();
        if(idx>0 && res[idx-1]===c) {
            if(heap.length===0) { console.log("IMPOSSIBLE"); rl.close(); return; }
            let [c2, f2] = heap.shift();
            res[idx++] = c2; f2--;
            if(f2>0) heap.unshift([c2, f2]);
            heap.unshift([c, f]);
        } else {
            res[idx++] = c; f--;
            if(f>0) heap.unshift([c, f]);
        }
        heap.sort((a,b)=>b[1]-a[1]);
    }
    console.log(res.join(''));
    rl.close();
});
