const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    if (n <= 1) { console.log("false"); rl.close(); return; }
    for (let i = 2; i * i <= n; i++) {
        if (n % i === 0) { console.log("false"); rl.close(); return; }
    }
    console.log("true");
    rl.close();
});
