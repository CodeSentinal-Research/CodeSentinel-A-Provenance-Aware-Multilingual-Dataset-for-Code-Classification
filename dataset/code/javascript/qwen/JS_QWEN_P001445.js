const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const s = lines[0];
        const n = parseInt(lines[1]);
        let words = [];
        for (let i = 2; i < 2 + n; i++) words.push(lines[i]);
        
        let count = 0;
        for (let w of words) {
            let i = 0, j = 0;
            while (i < s.length && j < w.length) {
                if (s[i] === w[j]) j++;
                i++;
            }
            if (j === w.length) count++;
        }
        console.log(count);
        rl.close();
    }
});
