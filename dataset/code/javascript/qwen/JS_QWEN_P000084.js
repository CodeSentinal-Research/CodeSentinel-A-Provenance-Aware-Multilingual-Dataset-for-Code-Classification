const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const age = parseInt(input.trim());
    console.log(age >= 18 ? "Eligible" : "Not Eligible");
    rl.close();
});
