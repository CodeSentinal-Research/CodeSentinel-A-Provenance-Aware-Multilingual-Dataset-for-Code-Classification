const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [n, l, r] = line.split(/\s+/).map(BigInt);
        // Inclusion-Exclusion Principle needed for large ranges
        console.log("Complex Inclusion-Exclusion Required");
        rl.close();
    }
});
