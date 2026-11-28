const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const hay = lines[0], needle = lines[1];
        console.log(hay.indexOf(needle));
        rl.close();
    }
});
