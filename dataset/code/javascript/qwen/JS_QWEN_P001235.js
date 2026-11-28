const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0]) + 1) {
        const n = parseInt(lines[0]);
        let jobs = [];
        for(let i=1; i<=n; i++) jobs.push(lines[i].split(/\s+/).map(Number));
        
        jobs.sort((a,b) => b[1]-a[1]);
        
        let maxDeadline = 0;
        for(let [,d] of jobs) maxDeadline = Math.max(maxDeadline, d);
        
        let slot = new Array(maxDeadline+1).fill(false);
        let profit=0;
        
        for(let [id, d, p] of jobs) {
            for(let j=Math.min(d, maxDeadline); j>0; j--) {
                if(!slot[j]) {
                    slot[j]=true;
                    profit+=p;
                    break;
                }
            }
        }
        console.log(profit);
        rl.close();
    }
});
