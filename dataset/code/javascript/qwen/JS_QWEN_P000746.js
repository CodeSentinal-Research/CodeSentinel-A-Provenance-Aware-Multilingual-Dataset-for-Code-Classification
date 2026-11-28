const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [n, k] = line.split(/\s+/).map(Number);
        function josephus(n, k) {
            if (n === 1) return 0;
            return (josephus(n - 1, k) + k) % n;
        }
        console.log(josephus(n, k) + 1);
        rl.close();
    }
});
