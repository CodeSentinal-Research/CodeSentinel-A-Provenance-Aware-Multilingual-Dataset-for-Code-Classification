const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const c = input.trim();
    if(c >= 'A' && c <= 'Z') console.log("Uppercase");
    else console.log("Lowercase");
    rl.close();
});
