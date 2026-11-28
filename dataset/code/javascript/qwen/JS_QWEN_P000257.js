const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const s1 = lines[0].toLowerCase().split('').sort().join('');
        const s2 = lines[1].toLowerCase().split('').sort().join('');
        console.log(s1 === s2 ? "Yes" : "No");
        rl.close();
    }
});
