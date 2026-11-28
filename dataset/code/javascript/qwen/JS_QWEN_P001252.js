const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0]) + 1) {
        const n = parseInt(lines[0]);
        let pairs = [];
        for(let i=1; i<=n; i++) pairs.push(lines[i].split(/\s+/).map(Number));
        
        pairs.sort((a,b)=>a[1]-b[1]);
        
        let count=0, lastEnd=-Infinity;
        for(let [s,e] of pairs) {
            if(s>lastEnd) { count++; lastEnd=e; }
        }
        console.log(count);
        rl.close();
    }
});
