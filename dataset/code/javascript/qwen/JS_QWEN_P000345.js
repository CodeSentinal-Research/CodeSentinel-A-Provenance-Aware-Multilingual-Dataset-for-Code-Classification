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
        console.log(JSON.stringify(c1) === JSON.stringify(c2) ? "Yes" : "No");
        rl.close();
    }
});
