const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let res = [];
    function genSub(i, curr) {
        if (i === s.length) {
            if (curr) res.push(curr);
            return;
        }
        genSub(i + 1, curr);
        genSub(i + 1, curr + s[i]);
    }
    genSub(0, "");
    console.log(res.sort().join("\n"));
    rl.close();
});
