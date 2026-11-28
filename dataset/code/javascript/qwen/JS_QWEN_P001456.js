const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let map = {};
    for (let i = 0; i <= s.length - 10; i++) {
        let sub = s.substring(i, i + 10);
        map[sub] = (map[sub] || 0) + 1;
    }
    let res = Object.keys(map).filter(k => map[k] > 1).sort();
    console.log(res.join("\n"));
    rl.close();
});
