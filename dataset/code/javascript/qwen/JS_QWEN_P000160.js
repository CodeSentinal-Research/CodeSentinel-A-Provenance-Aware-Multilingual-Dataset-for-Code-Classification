const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, target] = lines[0].split(/\s+/).map(Number);
        const arr = lines[1].split(/\s+/).map(Number);
        let set = new Set();
        let found = false;
        for(let x of arr) {
            if(set.has(target-x)) { found=true; break; }
            set.add(x);
        }
        console.log(found ? "Yes" : "No");
        rl.close();
    }
});
