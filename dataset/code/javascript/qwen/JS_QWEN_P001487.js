const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const s = lines[0];
        const n = parseInt(lines[1]);
        let queries = [];
        for (let i = 2; i < 2 + n; i++) queries.push(lines[i].split(/\s+/));
        
        let res = [];
        for (let [word, pattern] of queries) {
            let i = 0, j = 0;
            let match = true;
            while (i < word.length) {
                if (j < pattern.length && word[i] === pattern[j]) {
                    i++; j++;
                } else if (word[i] >= 'A' && word[i] <= 'Z') {
                    match = false; break;
                } else {
                    i++;
                }
            }
            res.push(match && j === pattern.length ? "YES" : "NO");
        }
        console.log(res.join("\n"));
        rl.close();
    }
});
