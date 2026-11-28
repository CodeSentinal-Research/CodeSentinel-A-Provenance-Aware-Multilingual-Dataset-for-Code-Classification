const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const candidates = lines[1].split(/\s+/).map(Number);
        const target = parseInt(lines[2]);
        let res = [];
        function backtrack(start, curr, sum) {
            if (sum === target) {
                res.push(curr.join(" "));
                return;
            }
            if (sum > target) return;
            for (let i = start; i < n; i++) {
                backtrack(i, [...curr, candidates[i]], sum + candidates[i]);
            }
        }
        backtrack(0, [], 0);
        console.log(res.join("\n"));
        rl.close();
    }
});
