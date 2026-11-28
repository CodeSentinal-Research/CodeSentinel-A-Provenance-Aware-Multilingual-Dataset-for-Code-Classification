const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let count = {};
    for(let c of s) count[c]=(count[c]||0)+1;
    for(let i=s.length-1; i>=0; i--) if(count[s[i]]===1) { console.log(s[i]); rl.close(); return; }
    console.log(-1);
    rl.close();
});
