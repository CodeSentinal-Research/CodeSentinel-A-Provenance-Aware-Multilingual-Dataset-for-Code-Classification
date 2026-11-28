const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const s = lines[0], t = lines[1];
        let xor = 0;
        for(let c of s) xor ^= c.charCodeAt(0);
        for(let c of t) xor ^= c.charCodeAt(0);
        console.log(String.fromCharCode(xor));
        rl.close();
    }
});
