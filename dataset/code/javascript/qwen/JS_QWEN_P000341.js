const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const val = (s) => parseInt(s.split('').map(c => c.charCodeAt(0)-97).join(''));
        console.log(val(lines[0]) + val(lines[1]) === val(lines[2]) ? "Yes" : "No");
        rl.close();
    }
});
