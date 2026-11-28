const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let res = [];
    function genCase(i, curr) {
        if (i === s.length) {
            res.push(curr);
            return;
        }
        if (/[a-zA-Z]/.test(s[i])) {
            genCase(i + 1, curr + s[i].toLowerCase());
            genCase(i + 1, curr + s[i].toUpperCase());
        } else {
            genCase(i + 1, curr + s[i]);
        }
    }
    genCase(0, "");
    console.log(res.join("\n"));
    rl.close();
});
