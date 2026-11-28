const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let present = new Array(n+1).fill(false);
        arr.forEach(x => present[Math.abs(x)] = true);
        let res = [];
        for(let i=1; i<=n; i++) if(!present[i]) res.push(i);
        console.log(res.join(" "));
        rl.close();
    }
});
