const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const seats = lines[1].split(/\s+/).map(Number);
        
        let maxDist=0, last=-1;
        for(let i=0; i<n; i++) {
            if(seats[i]===1) {
                if(last===-1) maxDist=i;
                else maxDist = Math.max(maxDist, Math.floor((i-last)/2));
                last=i;
            }
        }
        if(seats[n-1]===0) maxDist = Math.max(maxDist, n-1-last);
        console.log(maxDist);
        rl.close();
    }
});
