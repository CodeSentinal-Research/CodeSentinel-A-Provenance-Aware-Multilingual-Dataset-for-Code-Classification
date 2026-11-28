const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0]) + 1) {
        const n = parseInt(lines[0]);
        let people = [];
        for(let i=1; i<=n; i++) people.push(lines[i].split(/\s+/).map(Number));
        
        people.sort((a,b) => b[0]-a[0] || a[1]-b[1]);
        
        let res = [];
        for(let [h, k] of people) {
            res.splice(k, 0, [h,k]);
        }
        res.forEach(p => console.log(p.join(" ")));
        rl.close();
    }
});
