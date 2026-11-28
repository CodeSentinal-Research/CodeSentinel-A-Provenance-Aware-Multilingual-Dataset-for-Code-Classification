const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const [n, target] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let count = 0;
        function subSum(i, sum) {
            if (i === n) {
                if (sum === target) count++;
                return;
            }
            subSum(i + 1, sum + nums[i]);
            subSum(i + 1, sum);
        }
        subSum(0, 0);
        console.log(count);
        rl.close();
    }
});
