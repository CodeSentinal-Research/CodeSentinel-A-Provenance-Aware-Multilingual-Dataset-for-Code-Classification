const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [a, b, c] = lines[0].split(/\s+/).map(Number);
        let score=0;
        while(a>0 && b>0 && c>0) {
            if(a>=b && a>=c) { a--; b--; score++; }
            else if(b>=a && b>=c) { b--; c--; score++; }
            else { a--; c--; score++; }
        }
        score += Math.min(a,b) + Math.min(b,c) + Math.min(a,c); // Simplified
        console.log(score);
        rl.close();
    }
});
