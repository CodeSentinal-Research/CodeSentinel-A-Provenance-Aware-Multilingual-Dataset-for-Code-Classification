const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const s1 = lines[0], s2 = lines[1];
        console.log(s1.length === s2.length && (s1+s1).includes(s2) ? "Yes" : "No");
        rl.close();
    }
});
