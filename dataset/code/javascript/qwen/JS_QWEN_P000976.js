const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [x1, y1, x2, y2, x3, y3] = line.split(/\s+/).map(Number);
        let area = Math.abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)) / 2;
        console.log(area.toFixed(5));
        rl.close();
    }
});
