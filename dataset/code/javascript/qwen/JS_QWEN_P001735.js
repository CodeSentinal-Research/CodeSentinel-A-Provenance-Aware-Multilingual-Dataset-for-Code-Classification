const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 3) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const chars = lines[1].split(/\s+/);
        
        let res = [];
        function genStr(curr, len) {
            if (curr.length === len) {
                res.push(curr);
                return;
            }
            for (let c of chars) {
                genStr(curr + c, len);
            }
        }
        genStr("", k);
        console.log(res.join("\n"));
        rl.close();
    }
});
