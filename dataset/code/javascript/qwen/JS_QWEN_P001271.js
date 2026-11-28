const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const ranges = lines[1].split(/\s+/).map(Number);
        
        let intervals = [];
        for(let i=0; i<=n; i++) {
            let start = Math.max(0, i-ranges[i]);
            let end = Math.min(n, i+ranges[i]);
            intervals.push([start, end]);
        }
        
        intervals.sort((a,b)=>a[0]-b[0]);
        
        let taps=0, currEnd=0, nextEnd=0, idx=0;
        while(currEnd<n) {
            while(idx<=n && intervals[idx][0]<=currEnd) {
                nextEnd = Math.max(nextEnd, intervals[idx][1]);
                idx++;
            }
            if(nextEnd<=currEnd) { console.log(-1); rl.close(); return; }
            currEnd=nextEnd;
            taps++;
        }
        console.log(taps);
        rl.close();
    }
});
