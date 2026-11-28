const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const [n, target] = lines[0].split(/\s+/).map(Number);
        const candidates = lines[1].split(/\s+/).map(Number);
        
        let res = [];
        function backtrack(start, curr, sum) {
            if (sum === target) {
                res.push(curr.slice());
                return;
            }
            if (sum > target) return;
            for (let i = start; i < n; i++) {
                curr.push(candidates[i]);
                backtrack(i, curr, sum + candidates[i]);
                curr.pop();
            }
        }
        backtrack(0, [], 0);
        console.log(res.map(r => r.join(" ")).join("\n"));
        rl.close();
    }
});
