const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let n = s.length;
    let res = "";
    for (let len = n; len > 0; len--) {
        let found = false;
        let seen = new Set();
        for (let i = 0; i <= n - len; i++) {
            let sub = s.substring(i, i + len);
            if (seen.has(sub)) {
                res = sub;
                found = true;
                break;
            }
            seen.add(sub);
        }
        if (found) break;
    }
    console.log(res);
    rl.close();
});
