const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let zeros = arr.filter(x=>x===0).length;
        let res = Array(zeros).fill(0).concat(Array(n-zeros).fill(1));
        console.log(res.join(" "));
        rl.close();
    }
});
