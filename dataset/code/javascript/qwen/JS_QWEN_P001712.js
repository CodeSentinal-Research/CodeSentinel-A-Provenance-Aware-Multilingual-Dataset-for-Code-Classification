const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [n, k] = line.split(/\s+/).map(Number);
        let res = [];
        function combine(start, curr) {
            if (curr.length === k) {
                res.push(curr.join(" "));
                return;
            }
            for (let i = start; i <= n; i++) {
                combine(i + 1, [...curr, i]);
            }
        }
        combine(1, []);
        console.log(res.join("\n"));
        rl.close();
    }
});
