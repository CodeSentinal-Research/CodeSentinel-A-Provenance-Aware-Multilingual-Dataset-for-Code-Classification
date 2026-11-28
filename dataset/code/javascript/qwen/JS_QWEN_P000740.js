const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [n, m] = line.split(/\s+/).map(Number);
        let res = [];
        function solve(r, c, path) {
            if (r === n - 1 && c === m - 1) {
                res.push(path);
                return;
            }
            if (r + 1 < n) solve(r + 1, c, path + "V");
            if (c + 1 < m) solve(r, c + 1, path + "H");
            if (r + 1 < n && c + 1 < m) solve(r + 1, c + 1, path + "D");
        }
        solve(0, 0, "");
        console.log(res.join("\n"));
        rl.close();
    }
});
