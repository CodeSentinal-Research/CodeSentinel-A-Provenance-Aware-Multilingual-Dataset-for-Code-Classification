const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const encoded = lines[1].split(/\s+/).map(Number);
        let totalXor = 0;
        for (let i = 1; i <= n + 1; i++) totalXor ^= i;
        let encodedXor = 0;
        for (let i = 1; i < n; i += 2) encodedXor ^= encoded[i];
        let first = totalXor ^ encodedXor;
        let res = [first];
        for (let i = 0; i < n; i++) {
            res.push(res[res.length-1] ^ encoded[i]);
        }
        console.log(res.join(" "));
        rl.close();
    }
});
