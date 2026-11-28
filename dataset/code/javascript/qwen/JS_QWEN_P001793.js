const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const [n, target] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let res = [];
        function subSum(i, sum, curr) {
            if (i === n) {
                if (sum === target) res.push(curr.slice());
                return;
            }
            subSum(i + 1, sum + nums[i], [...curr, nums[i]]);
            subSum(i + 1, sum, curr);
        }
        subSum(0, 0, []);
        console.log(res.map(r => r.join(" ")).join("\n"));
        rl.close();
    }
});
