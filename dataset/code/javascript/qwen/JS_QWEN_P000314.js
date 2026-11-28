const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    let n = parseInt(input.trim());
    let res = "";
    while(n > 0) {
        n--;
        res = String.fromCharCode(65 + (n % 26)) + res;
        n = Math.floor(n / 26);
    }
    console.log(res);
    rl.close();
});
