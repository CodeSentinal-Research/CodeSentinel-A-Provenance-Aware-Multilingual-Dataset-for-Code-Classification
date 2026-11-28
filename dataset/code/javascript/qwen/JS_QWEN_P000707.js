const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let res = [];
    function genPar(open, close, curr) {
        if (curr.length === 2 * n) {
            res.push(curr);
            return;
        }
        if (open < n) genPar(open + 1, close, curr + "(");
        if (close < open) genPar(open, close + 1, curr + ")");
    }
    genPar(0, 0, "");
    console.log(res.join("\n"));
    rl.close();
});
