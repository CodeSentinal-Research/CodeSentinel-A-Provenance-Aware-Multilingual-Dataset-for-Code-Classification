const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    const s = Math.floor(Math.sqrt(n));
    console.log(s*s === n ? "Perfect Square" : "Not Perfect Square");
    rl.close();
});
