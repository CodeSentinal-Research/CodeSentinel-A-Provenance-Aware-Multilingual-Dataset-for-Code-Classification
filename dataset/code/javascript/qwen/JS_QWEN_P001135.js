const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        let incl = 0, excl = 0;
        for(let num of nums) {
            let newExcl = Math.max(incl, excl);
            incl = excl + num;
            excl = newExcl;
        }
        console.log(Math.max(incl, excl));
        rl.close();
    }
});
