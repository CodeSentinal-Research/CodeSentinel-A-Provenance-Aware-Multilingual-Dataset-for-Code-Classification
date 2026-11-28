const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let res = [];
    function abbr(i, curr, count) {
        if (i === s.length) {
            res.push(curr + (count > 0 ? count : ""));
            return;
        }
        abbr(i + 1, curr, count + 1);
        abbr(i + 1, curr + (count > 0 ? count : "") + s[i], 0);
    }
    abbr(0, "", 0);
    console.log(res.join("\n"));
    rl.close();
});
