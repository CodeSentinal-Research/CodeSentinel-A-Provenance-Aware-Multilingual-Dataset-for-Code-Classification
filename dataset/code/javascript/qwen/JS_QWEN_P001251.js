const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, t] = lines[0].split(/\s+/).map(Number);
        let boxes = [];
        for(let i=1; i<=n; i++) boxes.push(lines[i].split(/\s+/).map(Number));
        
        boxes.sort((a,b)=>b[1]-a[1]);
        
        let rem = t, units=0;
        for(let [cnt, u] of boxes) {
            let take = Math.min(cnt, rem);
            units += take*u;
            rem -= take;
            if(rem===0) break;
        }
        console.log(units);
        rl.close();
    }
});
