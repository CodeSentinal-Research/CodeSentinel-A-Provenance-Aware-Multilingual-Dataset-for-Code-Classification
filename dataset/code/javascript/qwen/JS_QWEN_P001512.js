const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, goal] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let prefixSum = 0;
        let count = 0;
        let map = {0: 1};
        
        for (let num of nums) {
            prefixSum += num;
            if (map[prefixSum - goal] !== undefined) {
                count += map[prefixSum - goal];
            }
            map[prefixSum] = (map[prefixSum] || 0) + 1;
        }
        
        console.log(count);
        rl.close();
    }
});
