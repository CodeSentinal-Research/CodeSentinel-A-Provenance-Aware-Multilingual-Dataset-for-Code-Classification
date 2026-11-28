const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', () => {
    for(let i=32; i<=126; i++) {
        console.log(`${i} ${String.fromCharCode(i)}`);
    }
    rl.close();
});
