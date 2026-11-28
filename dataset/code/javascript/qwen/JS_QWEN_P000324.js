const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let doubled = s + s;
    console.log(doubled.substring(1, doubled.length-1).includes(s) ? "Yes" : "No");
    rl.close();
});
