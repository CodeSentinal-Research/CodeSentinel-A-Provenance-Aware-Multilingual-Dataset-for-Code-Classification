const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let prefix = [0];
        for (let x of arr) prefix.push(prefix[prefix.length - 1] + x);
        console.log(prefix.slice(1).join(" "));
        rl.close();
    }
});
