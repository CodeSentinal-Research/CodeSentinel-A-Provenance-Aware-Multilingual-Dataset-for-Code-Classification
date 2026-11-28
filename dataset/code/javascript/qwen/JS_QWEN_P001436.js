const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let count = {b:0, a:0, l:0, o:0, n:0};
    for (let c of s) {
        if (count[c] !== undefined) count[c]++;
    }
    count.l = Math.floor(count.l / 2);
    count.o = Math.floor(count.o / 2);
    console.log(Math.min(count.b, count.a, count.l, count.o, count.n));
    rl.close();
});
