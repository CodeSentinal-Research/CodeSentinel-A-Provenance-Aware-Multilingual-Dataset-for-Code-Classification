const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let count={}, first={}, last={};
        let degree = 0;
        arr.forEach((x,i) => {
            count[x] = (count[x]||0)+1;
            if(count[x]>degree) degree=count[x];
            if(first[x]===undefined) first[x]=i;
            last[x]=i;
        });
        let minLen = n;
        for(let x in count) {
            if(count[x]===degree) {
                minLen = Math.min(minLen, last[x]-first[x]+1);
            }
        }
        console.log(minLen);
        rl.close();
    }
});
