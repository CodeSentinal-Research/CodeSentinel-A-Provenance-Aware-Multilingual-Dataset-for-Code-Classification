const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let even = 0, odd = 0;
    let s = n.toString();
    for(let c of s) {
        if(parseInt(c) % 2 === 0) even++;
        else odd++;
    }
    console.log(`${even} ${odd}`);
    rl.close();
});
