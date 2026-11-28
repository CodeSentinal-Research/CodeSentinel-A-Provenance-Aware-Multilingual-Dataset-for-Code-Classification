const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+1) {
        const n = parseInt(lines[0]);
        let pairs = [];
        for(let i=1; i<=n; i++) pairs.push(lines[i].split(/\s+/).map(Number));
        pairs.sort((a,b)=>a[1]-b[1]);
        let count=1, end=pairs[0][1];
        for(let i=1; i<n; i++) {
            if(pairs[i][0]>end) { count++; end=pairs[i][1]; }
        }
        console.log(count);
        rl.close();
    }
});
