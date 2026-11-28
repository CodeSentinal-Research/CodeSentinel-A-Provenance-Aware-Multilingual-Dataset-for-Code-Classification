const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const x = parseInt(input.trim());
    if (x < 0) { console.log("false"); rl.close(); return; }
    let rev = 0, orig = x;
    while (x > 0) {
        rev = rev * 10 + x % 10;
        x = Math.trunc(x / 10);
    }
    console.log(rev === orig ? "true" : "false");
    rl.close();
});
