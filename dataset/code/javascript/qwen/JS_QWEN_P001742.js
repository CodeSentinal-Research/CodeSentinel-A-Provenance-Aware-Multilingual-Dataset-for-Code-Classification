const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    function printN(i) {
        if (i > n) return;
        process.stdout.write(i + " ");
        printN(i + 1);
    }
    printN(1);
    console.log();
    rl.close();
});
