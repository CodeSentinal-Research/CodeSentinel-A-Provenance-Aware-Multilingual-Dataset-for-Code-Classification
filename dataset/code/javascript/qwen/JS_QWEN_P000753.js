const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        const target = parseInt(lines[2]);
        let res = [];
        function subSum(i, sum, curr) {
            if (i === n) {
                if (sum === target) res.push(curr.join(" "));
                return;
            }
            subSum(i + 1, sum + arr[i], [...curr, arr[i]]);
            subSum(i + 1, sum, curr);
        }
        subSum(0, 0, []);
        console.log(res.join("\n"));
        rl.close();
    }
});
