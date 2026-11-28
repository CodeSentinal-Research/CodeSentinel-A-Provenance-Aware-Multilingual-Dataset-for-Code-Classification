const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, xStr] = lines[0].split(/\s+/);
        const arr = lines[1].split(/\s+/).map(Number);
        const x = parseInt(xStr);
        console.log(arr.lastIndexOf(x));
        rl.close();
    }
});
