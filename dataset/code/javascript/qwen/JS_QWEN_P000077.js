const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const [x1, y1, x2, y2] = input.trim().split(/\s+/).map(Number);
    console.log(Math.sqrt(Math.pow(x2-x1, 2) + Math.pow(y2-y1, 2)).toFixed(2));
    rl.close();
});
