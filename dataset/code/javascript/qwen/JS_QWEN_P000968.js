const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [a1, m1, a2, m2] = line.split(/\s+/).map(BigInt);
        // Merge two congruences
        console.log("Merge Congruences Required");
        rl.close();
    }
});
