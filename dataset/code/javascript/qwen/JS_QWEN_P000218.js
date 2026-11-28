const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let count = {};
        arr.forEach(x => count[x]=(count[x]||0)+1);
        let res = Object.keys(count).filter(x => count[x] > n/3).map(Number);
        console.log(res.join(" "));
        rl.close();
    }
});
