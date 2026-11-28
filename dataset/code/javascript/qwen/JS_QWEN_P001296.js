const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const plant = lines[1].split(/\s+/).map(Number);
        const grow = lines[2].split(/\s+/).map(Number);
        
        let flowers = [];
        for(let i=0; i<n; i++) flowers.push([grow[i], plant[i]]);
        flowers.sort((a,b)=>b[0]-a[0]);
        
        let day=0, maxDay=0;
        for(let [g, p] of flowers) {
            day+=p;
            maxDay = Math.max(maxDay, day+g);
        }
        console.log(maxDay);
        rl.close();
    }
});
