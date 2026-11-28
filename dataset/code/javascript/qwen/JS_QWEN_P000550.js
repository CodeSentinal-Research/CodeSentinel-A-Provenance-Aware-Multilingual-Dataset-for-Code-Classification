const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const petrol = lines[1].split(/\s+/).map(Number);
        const dist = lines[2].split(/\s+/).map(Number);
        let start=0, total=0, curr=0;
        for(let i=0; i<n; i++) {
            let diff = petrol[i] - dist[i];
            total += diff;
            curr += diff;
            if(curr < 0) { start=i+1; curr=0; }
        }
        console.log(total>=0 ? start : -1);
        rl.close();
    }
});
