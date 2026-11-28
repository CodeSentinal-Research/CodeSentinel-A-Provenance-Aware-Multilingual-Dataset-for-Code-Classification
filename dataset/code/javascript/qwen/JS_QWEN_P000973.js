const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = parseInt(input.trim());
    let count = 0;
    for(let i=1; i<=6; i++) {
        for(let j=1; j<=6; j++) {
            if(i+j === s) count++;
        }
    }
    console.log((count/36).toFixed(5));
    rl.close();
});
