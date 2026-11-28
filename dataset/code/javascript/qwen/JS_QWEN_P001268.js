const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0]) + 1) {
        const n = parseInt(lines[0]);
        let events = [];
        for(let i=1; i<=n; i++) events.push(lines[i].split(/\s+/).map(Number));
        
        events.sort((a,b)=>a[1]-b[1]);
        
        let day=1, count=0;
        let heap = [];
        let idx=0;
        
        while(idx<n || heap.length>0) {
            if(heap.length===0) day=events[idx][0];
            while(idx<n && events[idx][0]<=day) {
                heap.push(events[idx][1]);
                idx++;
            }
            heap.sort((a,b)=>a-b);
            while(heap.length && heap[0]<day) heap.shift();
            
            if(heap.length>0) {
                heap.shift();
                count++;
            }
            day++;
        }
        console.log(count);
        rl.close();
    }
});
