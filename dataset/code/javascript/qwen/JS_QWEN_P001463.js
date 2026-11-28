const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, val] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let j = 0;
        for (let i = 0; i < n; i++) {
            if (nums[i] !== val) {
                nums[j++] = nums[i];
            }
        }
        console.log(`${j}\n${nums.slice(0, j).join(" ")}`);
        rl.close();
    }
});
