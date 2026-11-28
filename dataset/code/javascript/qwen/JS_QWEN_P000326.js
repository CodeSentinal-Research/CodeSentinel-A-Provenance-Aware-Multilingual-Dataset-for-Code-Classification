const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    console.log(input.trim().split(/\s+/).filter(x=>x).length);
    rl.close();
});
