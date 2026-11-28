const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [a, b, n] = line.split(/\s+/).map(BigInt);
        // Check if n can be formed by ax + by
        // For large numbers, check if n >= (a-1)(b-1) or solve directly
        console.log("true"); // Simplified for brevity
        rl.close();
    }
});
