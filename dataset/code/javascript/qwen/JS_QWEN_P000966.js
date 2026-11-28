const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 3) {
        const x = BigInt(lines[0]);
        const n = parseInt(lines[1]);
        let valid = true;
        for(let i=2; i<2+n; i++) {
            const [a, m] = lines[i].split(/\s+/).map(BigInt);
            if (x % m !== a) valid = false;
        }
        console.log(valid ? "true" : "false");
        rl.close();
    }
});
