const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const c = input.trim();
    if(/[a-zA-Z0-9]/.test(c)) console.log("Not Special Symbol");
    else console.log("Special Symbol");
    rl.close();
});
