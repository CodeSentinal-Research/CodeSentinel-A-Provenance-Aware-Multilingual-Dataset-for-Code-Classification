const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let evens = arr.filter(x=>x%2===0);
        let odds = arr.filter(x=>x%2!==0);
        console.log([...evens, ...odds].join(" "));
        rl.close();
    }
});
