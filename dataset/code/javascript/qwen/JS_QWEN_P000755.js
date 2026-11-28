const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const word = input.trim();
    let res = [];
    function genAbbr(i, curr, count) {
        if (i === word.length) {
            res.push(curr + (count > 0 ? count : ""));
            return;
        }
        genAbbr(i + 1, curr, count + 1);
        genAbbr(i + 1, curr + (count > 0 ? count : "") + word[i], 0);
    }
    genAbbr(0, "", 0);
    console.log(res.join("\n"));
    rl.close();
});
