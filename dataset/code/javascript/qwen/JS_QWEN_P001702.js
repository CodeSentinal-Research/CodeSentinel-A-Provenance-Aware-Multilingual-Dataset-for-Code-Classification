const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let minVal = Infinity;
        function findMin(i) {
            if (i === n) return;
            if (nums[i] < minVal) minVal = nums[i];
            findMin(i + 1);
        }
        findMin(0);
        console.log(minVal);
        rl.close();
    }
});
