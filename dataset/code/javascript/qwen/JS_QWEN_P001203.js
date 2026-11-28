const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0]) + 1) {
        const n = parseInt(lines[0]);
        let envelopes = [];
        for(let i=1; i<=n; i++) envelopes.push(lines[i].split(/\s+/).map(Number));
        
        envelopes.sort((a,b) => a[0]-b[0] || (a[0]===b[0] ? b[1]-a[1] : 0));
        
        let tails = [];
        for(let [, h] of envelopes) {
            let l=0, r=tails.length;
            while(l<r) {
                let m = Math.floor((l+r)/2);
                if(tails[m] < h) l=m+1;
                else r=m;
            }
            tails[l] = h;
        }
        console.log(tails.length);
        rl.close();
    }
});
