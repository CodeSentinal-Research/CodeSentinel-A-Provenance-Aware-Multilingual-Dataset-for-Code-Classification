const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let seen = new Set();
        let dupes = new Set();
        for (let x of nums) {
            if (seen.has(x)) dupes.add(x);
            else seen.add(x);
        }
        console.log([...dupes].sort((a,b)=>a-b).join(" "));
        rl.close();
    }
});
