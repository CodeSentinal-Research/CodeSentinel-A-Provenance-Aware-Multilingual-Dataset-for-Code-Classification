const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0]) + 1) {
        const n = parseInt(lines[0]);
        let intervals = [];
        for(let i=1; i<=n; i++) intervals.push(lines[i].split(/\s+/).map(Number));
        
        intervals.sort((a,b)=>a[0]-b[0]);
        
        let merged = [];
        for(let [s,e] of intervals) {
            if(merged.length===0 || merged[merged.length-1][1]<s) merged.push([s,e]);
            else merged[merged.length-1][1] = Math.max(merged[merged.length-1][1], e);
        }
        merged.forEach(m => console.log(m.join(" ")));
        rl.close();
    }
});
