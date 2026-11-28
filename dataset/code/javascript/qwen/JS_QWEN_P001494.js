const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let res = [];
    let low = 1, high = s.length + 1;
    for (let c of s) {
        if (c === 'I') res.push(low++);
        else res.push(high--);
    }
    res.push(low);
    console.log(res.join(" "));
    rl.close();
});
