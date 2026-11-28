const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const deck = lines[1].split(/\s+/).map(Number).sort((a,b)=>a-b);
        let res = new Array(n);
        let q = [];
        for(let i=0; i<n; i++) q.push(i);
        for(let card of deck) {
            res[q.shift()] = card;
            if(q.length) q.push(q.shift());
        }
        console.log(res.join(" "));
        rl.close();
    }
});
