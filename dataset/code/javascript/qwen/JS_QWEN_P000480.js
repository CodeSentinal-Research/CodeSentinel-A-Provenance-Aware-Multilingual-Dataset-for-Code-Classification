const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+1) {
        const n = parseInt(lines[0]);
        let ops = lines.slice(1);
        let scores = [];
        for(let op of ops) {
            if(op==='+') scores.push(scores[scores.length-1]+scores[scores.length-2]);
            else if(op==='D') scores.push(scores[scores.length-1]*2);
            else if(op==='C') scores.pop();
            else scores.push(parseInt(op));
        }
        console.log(scores.reduce((a,b)=>a+b, 0));
        rl.close();
    }
});
