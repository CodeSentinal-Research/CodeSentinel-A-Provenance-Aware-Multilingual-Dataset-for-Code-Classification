const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        let outDegree = new Array(n).fill(0);
        for(let i=1; i<=m; i++) {
            const [u, v] = lines[i].split(/\s+/).map(Number);
            outDegree[u-1]++;
        }
        let count = 0;
        for(let d of outDegree) if(d === 0) count++;
        console.log(count);
        rl.close();
    }
});
