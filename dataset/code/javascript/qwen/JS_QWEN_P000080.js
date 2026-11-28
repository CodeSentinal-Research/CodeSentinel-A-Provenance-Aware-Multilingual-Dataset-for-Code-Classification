const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const c = input.trim();
    if(/[a-zA-Z]/.test(c)) console.log("Alphabet");
    else console.log("Not Alphabet");
    rl.close();
});
