const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const s1 = lines[0], s2 = lines[1];
        let c1={}, c2={};
        for(let c of s1) c1[c]=(c1[c]||0)+1;
        for(let c of s2) c2[c]=(c2[c]||0)+1;
        let diff=0;
        for(let c in c1) diff+=Math.abs((c1[c]||0)-(c2[c]||0));
        for(let c in c2) if(!c1[c]) diff+=c2[c];
        console.log(diff<=1 ? "Yes" : "No");
        rl.close();
    }
});
