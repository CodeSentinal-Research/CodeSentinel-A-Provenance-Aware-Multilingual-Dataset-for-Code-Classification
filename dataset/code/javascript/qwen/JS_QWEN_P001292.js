const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const dist = lines[1].split(/\s+/).map(Number);
        const speed = lines[2].split(/\s+/).map(Number);
        
        let time = [];
        for(let i=0; i<n; i++) time.push(dist[i]/speed[i]);
        time.sort((a,b)=>a-b);
        
        let killed=0;
        for(let i=0; i<n; i++) {
            if(time[i]>i) killed++;
            else break;
        }
        console.log(killed);
        rl.close();
    }
});
