const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [a, b, f0, f1, n] = line.split(/\s+/).map(BigInt);
        // Matrix Exponentiation for Linear Recurrence
        console.log("Matrix Exponentiation Required");
        rl.close();
    }
});
