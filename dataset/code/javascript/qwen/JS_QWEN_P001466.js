const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim().replace(/[^a-zA-Z0-9]/g, '').toLowerCase();
    console.log(s === s.split('').reverse().join('') ? "YES" : "NO");
    rl.close();
});
