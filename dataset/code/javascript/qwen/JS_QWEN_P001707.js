const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let res = [];
    function genBin(curr, len) {
        if (curr.length === len) {
            res.push(curr);
            return;
        }
        genBin(curr + "0", len);
        if (curr.length === 0 || curr[curr.length - 1] !== '1') {
            genBin(curr + "1", len);
        }
    }
    genBin("", n);
    console.log(res.join("\n"));
    rl.close();
});
