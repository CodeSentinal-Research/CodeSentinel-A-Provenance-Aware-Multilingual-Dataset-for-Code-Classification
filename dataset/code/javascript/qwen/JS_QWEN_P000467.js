const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const [m, n, kStr] = lines[0].split(/\s+/).map(Number);
        const a1 = lines[1].split(/\s+/).map(Number);
        const a2 = lines[2].split(/\s+/).map(Number);
        const k = parseInt(kStr);
        const merged = [...a1, ...a2].sort((a,b)=>a-b);
        console.log(merged[k-1]);
        rl.close();
    }
});
