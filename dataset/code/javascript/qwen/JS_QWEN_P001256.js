const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let count = {};
    for(let c of s) count[c]=(count[c]||0)+1;
    
    let freqs = Object.values(count).sort((a,b)=>b-a);
    let del=0;
    let used = new Set();
    
    for(let f of freqs) {
        let curr = f;
        while(curr>0 && used.has(curr)) curr--;
        if(curr>0) used.add(curr);
        del += f-curr;
    }
    console.log(del);
    rl.close();
});
