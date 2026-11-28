const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const chars = lines[1].split(/\s+/);
        const k = parseInt(lines[2]);
        let res = [];
        function gen(curr) {
            if (curr.length === k) {
                res.push(curr);
                return;
            }
            for (let c of chars) gen(curr + c);
        }
        gen("");
        console.log(res.join("\n"));
        rl.close();
    }
});
