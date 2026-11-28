const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const s = lines[0];
        const t = lines[1];
        
        let i = 0, j = 0;
        while (i < s.length && j < t.length) {
            if (s[i] === t[j]) j++;
            i++;
        }
        console.log(j === t.length ? "YES" : "NO");
        rl.close();
    }
});
