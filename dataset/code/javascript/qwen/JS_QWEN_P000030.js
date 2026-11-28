const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
function gcd(a, b) { return b === 0 ? a : gcd(b, a % b); }
rl.on('line', (input) => {
    const [a, b] = input.trim().split(/\s+/).map(Number);
    console.log((a * b) / gcd(a, b));
    rl.close();
});
