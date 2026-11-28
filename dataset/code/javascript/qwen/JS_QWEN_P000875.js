const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [a, b, c] = line.split(/\s+/).map(Number);
        let flips = 0;
        for (let i = 0; i < 32; i++) {
            let bitA = (a >> i) & 1;
            let bitB = (b >> i) & 1;
            let bitC = (c >> i) & 1;
            if (((bitA | bitB) !== bitC)) flips++;
        }
        console.log(flips);
        rl.close();
    }
});
