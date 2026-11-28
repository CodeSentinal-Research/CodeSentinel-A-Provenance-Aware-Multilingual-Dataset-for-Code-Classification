const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let upper = s === s.toUpperCase();
    let lower = s === s.toLowerCase();
    let title = s[0] === s[0].toUpperCase() && s.substring(1) === s.substring(1).toLowerCase();
    console.log(upper || lower || title ? "Yes" : "No");
    rl.close();
});
