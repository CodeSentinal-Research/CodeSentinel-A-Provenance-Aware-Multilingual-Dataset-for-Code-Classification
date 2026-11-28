const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const sweetness = lines[1].split(/\s+/).map(Number);
        
        let l=1, r=sweetness.reduce((a,b)=>a+b, 0);
        while(l<r) {
            let mid = Math.floor((l+r+1)/2);
            let pieces=0, curr=0;
            for(let s of sweetness) {
                curr+=s;
                if(curr>=mid) { pieces++; curr=0; }
            }
            if(pieces>=k+1) l=mid;
            else r=mid-1;
        }
        console.log(l);
        rl.close();
    }
});
