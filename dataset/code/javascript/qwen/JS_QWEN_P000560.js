const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const q = lines[1].split(/\s+/).map(Number);
        let half = n/2;
        let firstHalf = q.splice(0, half);
        let res = [];
        for(let i=0; i<half; i++) {
            res.push(firstHalf[i]);
            res.push(q[i]);
        }
        console.log(res.join(" "));
        rl.close();
    }
});
