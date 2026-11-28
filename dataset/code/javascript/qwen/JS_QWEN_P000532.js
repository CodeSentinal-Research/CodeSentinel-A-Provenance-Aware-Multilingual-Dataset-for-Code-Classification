const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const tickets = lines[1].split(/\s+/).map(Number);
        const k = parseInt(lines[2]);
        let time = 0;
        for(let i=0; i<n; i++) {
            if(tickets[i] <= tickets[k]) time += tickets[i];
            else if(i <= k) time += tickets[k];
            else time += tickets[k]-1;
        }
        console.log(time);
        rl.close();
    }
});
