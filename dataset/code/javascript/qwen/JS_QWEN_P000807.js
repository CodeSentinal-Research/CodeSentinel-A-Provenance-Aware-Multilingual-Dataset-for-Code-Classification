const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let map = {0: 1};
    let balance = 0;
    let count = 0;
    const vowels = new Set(['a','e','i','o','u']);
    for (let c of s) {
        balance += (vowels.has(c) ? 1 : -1);
        if (map[balance] !== undefined) count += map[balance];
        map[balance] = (map[balance] || 0) + 1;
    }
    console.log(count);
    rl.close();
});
