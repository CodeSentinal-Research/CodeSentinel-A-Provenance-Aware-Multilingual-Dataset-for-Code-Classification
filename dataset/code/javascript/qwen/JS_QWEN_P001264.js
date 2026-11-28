const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0]) + 1) {
        const n = parseInt(lines[0]);
        let tasks = [];
        for(let i=1; i<=n; i++) tasks.push(lines[i].split(/\s+/).map(Number));
        
        tasks.sort((a,b) => b[1]-a[1]);
        
        let energy=0, minStart=0;
        for(let [act, req] of tasks) {
            minStart = Math.max(minStart, energy+req);
            energy += act;
        }
        console.log(minStart);
        rl.close();
    }
});
