const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, w] = lines[0].split(/\s+/).map(Number);
        let items = [];
        for(let i=1; i<=n; i++) items.push(lines[i].split(/\s+/).map(Number));
        
        items.sort((a,b) => (b[1]/b[0]) - (a[1]/a[0]));
        
        let rem = w, val=0;
        for(let [wt, vl] of items) {
            if(rem>=wt) { rem-=wt; val+=vl; }
            else { val += (vl/wt)*rem; rem=0; break; }
        }
        console.log(val.toFixed(2));
        rl.close();
    }
});
