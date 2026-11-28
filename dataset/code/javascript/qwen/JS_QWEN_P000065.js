const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
function gcd(a, b) { return b === 0 ? a : gcd(b, a % b); }
function lcm(a, b) { return (a * b) / gcd(a, b); }
rl.on('line', (input) => {
    const [a, b, c] = input.trim().split(/\s+/).map(Number);
    console.log(lcm(a, lcm(b, c)));
    rl.close();
});
