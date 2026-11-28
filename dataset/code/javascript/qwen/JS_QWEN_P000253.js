const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim().toLowerCase();
    let count = 0;
    for(let c of s) if(['a','e','i','o','u'].includes(c)) count++;
    console.log(count);
    rl.close();
});
