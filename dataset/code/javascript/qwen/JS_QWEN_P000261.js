const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    console.log(input.trim().split('').map(c => c===c.toUpperCase()?c.toLowerCase():c.toUpperCase()).join(''));
    rl.close();
});
