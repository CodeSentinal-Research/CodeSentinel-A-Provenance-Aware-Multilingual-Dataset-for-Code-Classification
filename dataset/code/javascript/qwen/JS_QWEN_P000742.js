const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    function print1ToN(i, n) {
        if (i > n) return;
        process.stdout.write(i + " ");
        print1ToN(i + 1, n);
    }
    print1ToN(1, n);
    console.log();
    rl.close();
});
