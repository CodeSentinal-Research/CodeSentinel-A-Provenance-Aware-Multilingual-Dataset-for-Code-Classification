const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+1) {
        const n = parseInt(lines[0]);
        let jobs = [];
        for(let i=1; i<=n; i++) jobs.push(lines[i].split(/\s+/).map(Number));
        jobs.sort((a,b)=>b[2]-a[2]);
        let slot = new Array(n).fill(false);
        let profit=0, count=0;
        jobs.forEach(j => {
            for(let d=Math.min(n, j[1])-1; d>=0; d--) {
                if(!slot[d]) { slot[d]=true; profit+=j[2]; count++; break; }
            }
        });
        console.log(`${count} ${profit}`);
        rl.close();
    }
});
