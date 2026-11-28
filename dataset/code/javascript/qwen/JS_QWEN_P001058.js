const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 1) {
        const q = parseInt(lines[0]);
        // Complex Class Implementation
        console.log("Class Implementation Required");
        rl.close();
    }
});
