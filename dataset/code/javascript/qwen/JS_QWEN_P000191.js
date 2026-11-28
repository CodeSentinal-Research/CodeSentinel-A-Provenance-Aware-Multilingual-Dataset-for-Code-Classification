const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let c0=0, c1=0, c2=0;
        arr.forEach(x => x===0?c0++:x===1?c1++:c2++);
        let res = Array(c0).fill(0).concat(Array(c1).fill(1)).concat(Array(c2).fill(2));
        console.log(res.join(" "));
        rl.close();
    }
});
