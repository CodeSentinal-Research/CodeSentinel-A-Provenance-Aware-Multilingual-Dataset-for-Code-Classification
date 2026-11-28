const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const s = lines[0];
        const n = parseInt(lines[1]);
        let dict = [];
        for (let i = 2; i < 2 + n; i++) dict.push(lines[i]);
        
        dict.sort((a,b) => b.length - a.length || a.localeCompare(b));
        for (let w of dict) {
            let i = 0, j = 0;
            while (i < s.length && j < w.length) {
                if (s[i] === w[j]) j++;
                i++;
            }
            if (j === w.length) { console.log(w); rl.close(); return; }
        }
        console.log("");
        rl.close();
    }
});
