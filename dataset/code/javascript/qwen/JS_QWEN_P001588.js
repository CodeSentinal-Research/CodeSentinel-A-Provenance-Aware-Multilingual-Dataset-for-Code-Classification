const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let count = 0;
        let prefixOdd = 0;
        let map = {0: 1};
        
        for (let num of nums) {
            if (num % 2 !== 0) prefixOdd++;
            if (map[prefixOdd - k] !== undefined) {
                count += map[prefixOdd - k];
            }
            map[prefixOdd] = (map[prefixOdd] || 0) + 1;
        }
        
        console.log(count);
        rl.close();
    }
});
