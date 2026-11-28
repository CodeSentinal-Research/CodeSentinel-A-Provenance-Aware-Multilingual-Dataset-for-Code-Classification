const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const v1 = lines[0], v2 = lines[1];
        let p1 = v1.split('.').map(Number), p2 = v2.split('.').map(Number);
        let len = Math.max(p1.length, p2.length);
        for (let i = 0; i < len; i++) {
            let n1 = p1[i] || 0, n2 = p2[i] || 0;
            if (n1 > n2) { console.log(1); rl.close(); return; }
            if (n1 < n2) { console.log(-1); rl.close(); return; }
        }
        console.log(0);
        rl.close();
    }
});
