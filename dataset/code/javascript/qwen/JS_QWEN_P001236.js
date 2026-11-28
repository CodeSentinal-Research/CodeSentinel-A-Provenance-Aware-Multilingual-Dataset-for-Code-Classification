const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0]) + 1) {
        const n = parseInt(lines[0]);
        let balloons = [];
        for(let i=1; i<=n; i++) balloons.push(lines[i].split(/\s+/).map(Number));
        
        balloons.sort((a,b)=>a[1]-b[1]);
        
        let arrows=0, lastEnd=-Infinity;
        for(let [s,e] of balloons) {
            if(s>lastEnd) { arrows++; lastEnd=e; }
        }
        console.log(arrows);
        rl.close();
    }
});
