const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const c = input.trim();
    if(/[0-9]/.test(c)) console.log("Digit");
    else console.log("Not Digit");
    rl.close();
});
