const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let unbal=0, swaps=0;
    for(let c of s) {
        if(c==='[') unbal++;
        else unbal--;
        if(unbal<0) { swaps+=-unbal; unbal=0; } // Simplified
    }
    console.log(swaps);
    rl.close();
});
