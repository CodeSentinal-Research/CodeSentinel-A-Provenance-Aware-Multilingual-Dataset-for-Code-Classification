const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const street = lines[1];
        
        let cops = [], thieves = [];
        for(let i=0; i<n; i++) {
            if(street[i]==='P') cops.push(i);
            else thieves.push(i);
        }
        
        let caught = 0;
        let ci=0, ti=0;
        while(ci<cops.length && ti<thieves.length) {
            if(Math.abs(cops[ci]-thieves[ti]) <= k) {
                caught++;
                ci++;
                ti++;
            } else if(cops[ci] < thieves[ti]) {
                ci++;
            } else {
                ti++;
            }
        }
        console.log(caught);
        rl.close();
    }
});
