const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const w1 = lines[0], w2 = lines[1];
        let c1={}, c2={};
        for(let c of w1) c1[c]=(c1[c]||0)+1;
        for(let c of w2) c2[c]=(c2[c]||0)+1;
        let ok = true;
        for(let c in c1) if(Math.abs((c1[c]||0)-(c2[c]||0))>3) ok=false;
        for(let c in c2) if(Math.abs((c1[c]||0)-(c2[c]||0))>3) ok=false;
        console.log(ok ? "Yes" : "No");
        rl.close();
    }
});
