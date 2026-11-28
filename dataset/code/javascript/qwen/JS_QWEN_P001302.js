const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0]) + 1) {
        const n = parseInt(lines[0]);
        let events = [];
        for(let i=1; i<=n; i++) {
            const [s, e] = lines[i].split(/\s+/).map(Number);
            events.push([s, 1]);
            events.push([e, -1]);
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
