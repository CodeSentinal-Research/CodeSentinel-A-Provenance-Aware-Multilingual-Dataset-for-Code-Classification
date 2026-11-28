const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    const hasZero = s.includes('0');
    const startsWithZero = s[0] === '0';
    console.log(hasZero && !startsWithZero ? "Duck" : "Not Duck");
    rl.close();
});
