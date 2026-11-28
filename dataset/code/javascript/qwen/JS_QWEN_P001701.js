const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let maxVal = -Infinity;
        function findMax(i) {
            if (i === n) return;
            if (nums[i] > maxVal) maxVal = nums[i];
            findMax(i + 1);
        }
        findMax(0);
        console.log(maxVal);
        rl.close();
    }
});
