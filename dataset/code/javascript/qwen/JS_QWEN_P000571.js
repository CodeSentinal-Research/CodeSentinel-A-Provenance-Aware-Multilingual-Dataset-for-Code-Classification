const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [n, k] = line.split(/\s+/).map(Number);
        let q = [];
        for(let i=1; i<=n; i++) q.push(i);
        while(q.length>1) {
            for(let i=0; i<k-1; i++) q.push(q.shift());
            q.shift();
        }
        console.log(q[0]);
        rl.close();
    }
});
