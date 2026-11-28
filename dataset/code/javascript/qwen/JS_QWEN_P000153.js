const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let pos = arr.filter(x=>x>0), neg = arr.filter(x=>x<0);
        let res = [], i=0, j=0;
        while(i<pos.length && j<neg.length) {
            res.push(pos[i++]);
            res.push(neg[j++]);
        }
        while(i<pos.length) res.push(pos[i++]);
        while(j<neg.length) res.push(neg[j++]);
        console.log(res.join(" "));
        rl.close();
    }
});
