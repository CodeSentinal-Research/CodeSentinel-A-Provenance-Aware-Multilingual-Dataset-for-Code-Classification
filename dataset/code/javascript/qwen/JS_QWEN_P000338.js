const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const w1 = lines[0].split(/\s+/).join('');
        const w2 = lines[1].split(/\s+/).join('');
        console.log(w1 === w2 ? "Yes" : "No");
        rl.close();
    }
});
