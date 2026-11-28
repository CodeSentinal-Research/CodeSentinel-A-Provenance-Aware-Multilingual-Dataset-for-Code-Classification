const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const x = parseInt(input.trim());
    let res = 0;
    let overflow = false;
    while (x !== 0) {
        let digit = x % 10;
        x = Math.trunc(x / 10);
        if (res > Math.floor(2147483647 / 10) || (res === Math.floor(2147483647 / 10) && digit > 7)) {
            console.log(0); rl.close(); return;
        }
        res = res * 10 + digit;
    }
    console.log(res);
    rl.close();
});
