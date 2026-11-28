const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        const h1 = lines[1].split(/\s+/).map(Number);
        const h2 = lines[2].split(/\s+/).map(Number);
        console.log(JSON.stringify(h1) === JSON.stringify(h2) ? "YES" : "NO");
        rl.close();
    }
});
