const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        const target = parseInt(lines[2]);
        
        let count = 0;
        function countOcc(i) {
            if (i === n) return;
            if (nums[i] === target) count++;
            countOcc(i + 1);
        }
        countOcc(0);
        console.log(count);
        rl.close();
    }
});
