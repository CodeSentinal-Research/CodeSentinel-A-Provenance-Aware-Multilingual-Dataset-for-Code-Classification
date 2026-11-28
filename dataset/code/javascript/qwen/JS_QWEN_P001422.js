const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        let rows = ["qwertyuiop", "asdfghjkl", "zxcvbnm"];
        let res = [];
        for (let i = 1; i <= n; i++) {
            let word = lines[i].toLowerCase();
            let row = -1;
            let valid = true;
            for (let c of word) {
                let r = rows.findIndex(r => r.includes(c));
                if (row === -1) row = r;
                else if (r !== row) { valid = false; break; }
            }
            if (valid) res.push(lines[i]);
        }
        console.log(res.sort().join("\n"));
        rl.close();
    }
});
