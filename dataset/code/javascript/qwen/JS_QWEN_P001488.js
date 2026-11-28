const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let l = 0, r = s.length - 1;
    while (l < r && s[l] === s[r]) {
        if (s[l] === s[0]) { l++; r--; }
        else break;
    }
    console.log(r - l + 1);
    rl.close();
});
