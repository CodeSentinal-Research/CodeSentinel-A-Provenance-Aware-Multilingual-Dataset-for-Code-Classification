const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let swaps = 0, blacks = 0;
    for (let c of s) {
        if (c === 'B') blacks++;
        else swaps += blacks;
    }
    console.log(swaps);
    rl.close();
});
