const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+1) {
        const n = parseInt(lines[0]);
        let acts = [];
        for(let i=1; i<=n; i++) acts.push(lines[i].split(/\s+/).map(Number));
        acts.sort((a,b)=>a[1]-b[1]);
        let count=1, end=acts[0][1];
        for(let i=1; i<n; i++) {
            if(acts[i][0]>=end) { count++; end=acts[i][1]; }
        }
        console.log(count);
        rl.close();
    }
});
