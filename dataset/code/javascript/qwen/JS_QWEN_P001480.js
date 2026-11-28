const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let lastIdx = {};
    for (let i = 0; i < s.length; i++) lastIdx[s[i]] = i;
    
    let res = [];
    let start = 0, end = 0;
    for (let i = 0; i < s.length; i++) {
        end = Math.max(end, lastIdx[s[i]]);
        if (i === end) {
            res.push(end - start + 1);
            start = i + 1;
        }
    }
    console.log(res.join(" "));
    rl.close();
});
