const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0]) + 1) {
        const n = parseInt(lines[0]);
        let arr = [];
        for(let i=1; i<=n; i++) arr.push(lines[i].split(/\s+/).map(Number));
        
        let events = [];
        for(let [a,d] of arr) {
            events.push([a, 1]);
            events.push([d, -1]);
        }
        events.sort((a,b)=>a[0]-b[0] || a[1]-b[1]);
        
        let plat=0, maxP=0;
        for(let [_, type] of events) {
            plat+=type;
            maxP = Math.max(maxP, plat);
        }
        console.log(maxP);
        rl.close();
    }
});
