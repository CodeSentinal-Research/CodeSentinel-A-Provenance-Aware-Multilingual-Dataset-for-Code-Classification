const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let res = [];
        function subsetSum(i, sum) {
            if (i === n) {
                res.push(sum);
                return;
            }
            subsetSum(i + 1, sum + arr[i]);
            subsetSum(i + 1, sum);
        }
        subsetSum(0, 0);
        console.log(res.sort((a,b)=>a-b).join(" "));
        rl.close();
    }
});
