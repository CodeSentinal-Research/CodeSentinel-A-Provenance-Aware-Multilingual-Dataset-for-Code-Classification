const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let res = [];
    function genSub(s, curr, i) {
        if (i === s.length) {
            if (curr) res.push(curr);
            return;
        }
        genSub(s, curr, i + 1);
        genSub(s, curr + s[i], i + 1);
    }
    genSub(s, "", 0);
    console.log(res.sort().join("\n"));
    rl.close();
});
