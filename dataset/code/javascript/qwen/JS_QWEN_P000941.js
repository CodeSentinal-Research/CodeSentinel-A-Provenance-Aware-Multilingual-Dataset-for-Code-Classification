const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const piles = lines[1].split(/\s+/).map(Number);
        let xor = 0;
        for(let p of piles) xor ^= p;
        console.log(xor !== 0 ? "First" : "Second");
        rl.close();
    }
});
