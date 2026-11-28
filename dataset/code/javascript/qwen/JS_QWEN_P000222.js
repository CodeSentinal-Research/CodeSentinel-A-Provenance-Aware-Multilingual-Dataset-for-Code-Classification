const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        const dep = lines[2].split(/\s+/).map(Number);
        let events = [];
        for(let i=0; i<n; i++) { events.push([arr[i], 1]); events.push([dep[i], -1]); }
        events.sort((a,b)=>a[0]-b[0] || a[1]-b[1]);
        let plat=0, maxP=0;
        events.forEach(e => { plat+=e[1]; maxP=Math.max(maxP, plat); });
        console.log(maxP);
        rl.close();
    }
});
