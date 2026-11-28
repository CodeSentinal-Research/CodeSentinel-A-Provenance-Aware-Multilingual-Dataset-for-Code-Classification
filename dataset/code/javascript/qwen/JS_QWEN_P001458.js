const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let n = s.length;
    let set = new Set();
    for (let i = 0; i < n; i++) {
        for (let j = i; j < n; j++) {
            let sub = s.substring(i, j + 1);
            if (sub === sub.split('').reverse().join('')) set.add(sub);
        }
    }
    console.log(set.size);
    rl.close();
});
