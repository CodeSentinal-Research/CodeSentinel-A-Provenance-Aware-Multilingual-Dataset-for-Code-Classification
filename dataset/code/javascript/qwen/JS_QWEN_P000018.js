const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const y = parseInt(input.trim());
    if ((y % 4 === 0 && y % 100 !== 0) || (y % 400 === 0)) console.log("Leap Year");
    else console.log("Not a Leap Year");
    rl.close();
});
