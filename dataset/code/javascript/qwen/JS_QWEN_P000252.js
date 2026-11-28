const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    console.log(s === s.split('').reverse().join('') ? "Yes" : "No");
    rl.close();
});
