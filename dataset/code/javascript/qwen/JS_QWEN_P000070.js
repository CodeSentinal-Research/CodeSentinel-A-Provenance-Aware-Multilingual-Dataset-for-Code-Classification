const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const [a, b, c] = input.trim().split(/\s+/).map(Number);
    if(a+b>c && a+c>b && b+c>a) console.log("Valid");
    else console.log("Invalid");
    rl.close();
});
