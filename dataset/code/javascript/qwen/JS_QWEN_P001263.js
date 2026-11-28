const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0]) + 1) {
        const n = parseInt(lines[0]);
        let costs = [];
        for(let i=1; i<=n; i++) costs.push(lines[i].split(/\s+/).map(Number));
        
        costs.sort((a,b) => (a[0]-a[1]) - (b[0]-b[1]));
        
        let cost=0;
        for(let i=0; i<n/2; i++) cost+=costs[i][0];
        for(let i=n/2; i<n; i++) cost+=costs[i][1];
        console.log(cost);
        rl.close();
    }
});
