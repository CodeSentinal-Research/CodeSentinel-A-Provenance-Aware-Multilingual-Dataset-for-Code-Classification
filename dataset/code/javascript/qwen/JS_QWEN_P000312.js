const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const v1 = lines[0].split('.').map(Number);
        const v2 = lines[1].split('.').map(Number);
        const len = Math.max(v1.length, v2.length);
        for(let i=0; i<len; i++) {
            let n1 = v1[i] || 0, n2 = v2[i] || 0;
            if(n1 > n2) { console.log(1); rl.close(); return; }
            if(n1 < n2) { console.log(-1); rl.close(); return; }
        }
        console.log(0);
        rl.close();
    }
});
