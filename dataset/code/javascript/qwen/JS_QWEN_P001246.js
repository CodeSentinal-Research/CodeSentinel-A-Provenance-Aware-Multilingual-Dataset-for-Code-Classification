const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, power] = lines[0].split(/\s+/).map(Number);
        const tokens = lines[1].split(/\s+/).map(Number);
        
        tokens.sort((a,b)=>a-b);
        
        let l=0, r=n-1, score=0, maxScore=0;
        while(l<=r) {
            if(power>=tokens[l]) {
                power-=tokens[l++];
                score++;
                maxScore = Math.max(maxScore, score);
            } else if(score>0) {
                power+=tokens[r--];
                score--;
            } else break;
        }
        console.log(maxScore);
        rl.close();
    }
});
