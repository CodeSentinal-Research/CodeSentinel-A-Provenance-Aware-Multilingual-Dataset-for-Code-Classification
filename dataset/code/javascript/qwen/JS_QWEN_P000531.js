const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+1) {
        const n = parseInt(lines[0]);
        const times = lines.slice(1).map(Number);
        let q = [];
        let res = [];
        for(let t of times) {
            q.push(t);
            while(q[0] < t-3000) q.shift();
            res.push(q.length);
        }
        console.log(res.join("\n"));
        rl.close();
    }
});
