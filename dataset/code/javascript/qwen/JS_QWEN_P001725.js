const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let found = false;
    function check(start, prevNum) {
        if (start === s.length) return true;
        let num = 0;
        for (let i = start; i < s.length; i++) {
            num = num * 10 + parseInt(s[i]);
            if (prevNum !== null && num !== prevNum - 1) continue;
            if (check(i + 1, num)) return true;
            if (num === 0) break;
        }
        return false;
    }
    for (let i = 1; i < s.length; i++) {
        let first = parseInt(s.substring(0, i));
        if (check(i, first)) { found = true; break; }
    }
    console.log(found ? "true" : "false");
    rl.close();
});
