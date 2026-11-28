const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        let intervals = [];
        for(let i=1; i<=n; i++) intervals.push(lines[i].split(/\s+/).map(Number));
        const newInt = lines[n+1].split(/\s+/).map(Number);
        
        intervals.sort((a,b)=>a[0]-b[0]);
        
        let merged = [];
        let inserted = false;
        for(let [s,e] of intervals) {
            if(e < newInt[0]) merged.push([s,e]);
            else if(s > newInt[1]) {
                if(!inserted) { merged.push(newInt); inserted=true; }
                merged.push([s,e]);
            } else {
                newInt[0] = Math.min(newInt[0], s);
                newInt[1] = Math.max(newInt[1], e);
            }
        }
        if(!inserted) merged.push(newInt);
        merged.forEach(m => console.log(m.join(" ")));
        rl.close();
    }
});
