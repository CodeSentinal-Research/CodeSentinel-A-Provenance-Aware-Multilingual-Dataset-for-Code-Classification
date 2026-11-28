const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    if (n > 0) console.log("Positive");
    else if (n < 0) console.log("Negative");
    else console.log("Zero");
    rl.close();
});
