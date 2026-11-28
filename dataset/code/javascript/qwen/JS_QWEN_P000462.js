const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 4) {
        const n1 = parseInt(lines[0]);
        const a1 = lines[1].split(/\s+/).map(Number);
        const n2 = parseInt(lines[2]);
        const a2 = lines[3].split(/\s+/).map(Number);
        let s1 = new Set(a1), s2 = new Set(a2);
        let common = [...s1].filter(x => s2.has(x)).sort((a,b)=>a-b);
        console.log(common.join(" "));
        rl.close();
    }
});
