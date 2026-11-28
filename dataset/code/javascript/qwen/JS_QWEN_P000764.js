const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const s = lines[0];
        const k = parseInt(lines[1]);
        let decodedLen = 0;
        for (let c of s) {
            if (c >= '0' && c <= '9') decodedLen *= parseInt(c);
            else decodedLen++;
        }
        k = k % decodedLen;
        for (let i = s.length - 1; i >= 0; i--) {
            k = k % decodedLen;
            if (k === 0 && s[i] >= 'a' && s[i] <= 'z') {
                console.log(s[i]);
                rl.close();
                return;
            }
            if (s[i] >= '0' && s[i] <= '9') decodedLen /= parseInt(s[i]);
            else decodedLen--;
        }
        rl.close();
    }
});
