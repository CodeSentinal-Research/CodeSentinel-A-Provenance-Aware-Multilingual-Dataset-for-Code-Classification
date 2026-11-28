const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let res = [];
        function findInc(idx, curr) {
            if (curr.length >= 2) res.push(curr.join(" "));
            let used = new Set();
            for (let i = idx; i < n; i++) {
                if (used.has(arr[i])) continue;
                if (curr.length === 0 || arr[i] >= curr[curr.length - 1]) {
                    used.add(arr[i]);
                    findInc(i + 1, [...curr, arr[i]]);
                }
            }
        }
        findInc(0, []);
        console.log(res.join("\n"));
        rl.close();
    }
});
