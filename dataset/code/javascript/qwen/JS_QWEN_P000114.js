const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const arr = lines[1].split(/\s+/).map(Number);
        const rot = k % n;
        const res = [...arr.slice(rot), ...arr.slice(0, rot)];
        console.log(res.join(" "));
        rl.close();
    }
});
