const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const num = parseInt(input.trim());
    let l = 1, r = num;
    while (l <= r) {
        let m = Math.floor((l + r) / 2);
        if (m * m === num) { console.log("true"); rl.close(); return; }
        else if (m * m < num) l = m + 1;
        else r = m - 1;
    }
    console.log("false");
    rl.close();
});
