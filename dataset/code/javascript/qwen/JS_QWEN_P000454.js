const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, dStr] = lines[0].split(/\s+/).map(Number);
        const weights = lines[1].split(/\s+/).map(Number);
        const d = parseInt(dStr);
        let l=Math.max(...weights), r=weights.reduce((a,b)=>a+b,0);
        while(l<r) {
            let mid = Math.floor((l+r)/2);
            let days=1, curr=0;
            for(let w of weights) {
                if(curr+w > mid) { days++; curr=w; }
                else curr+=w;
            }
            if(days>d) l=mid+1;
            else r=mid;
        }
        console.log(l);
        rl.close();
    }
});
