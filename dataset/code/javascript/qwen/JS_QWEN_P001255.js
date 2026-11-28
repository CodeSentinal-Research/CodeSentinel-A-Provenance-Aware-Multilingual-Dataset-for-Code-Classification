const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let bal=0, add=0;
    for(let c of s) {
        if(c==='(') bal++;
        else bal--;
        if(bal<0) { add++; bal=0; }
    }
    console.log(add+bal);
    rl.close();
});
