const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let res = [];
    function gen(i, curr) {
        if(i===s.length) { res.push(curr); return; }
        if(/[a-zA-Z]/.test(s[i])) {
            gen(i+1, curr+s[i].toLowerCase());
            gen(i+1, curr+s[i].toUpperCase());
        } else {
            gen(i+1, curr+s[i]);
        }
    }
    gen(0, "");
    console.log(res.join("\n"));
    rl.close();
});
