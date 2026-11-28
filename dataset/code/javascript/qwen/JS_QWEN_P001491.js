const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const scores = lines[1].split(/\s+/).map(Number);
        
        scores.sort((a,b)=>a-b);
        console.log(scores[k-1] - scores[0]);
        rl.close();
    }
});
