const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        function rev(x) {
            return parseInt(x.toString().split('').reverse().join(''));
        }
        
        let map = {};
        let count = 0;
        for (let x of nums) {
            let val = x - rev(x);
            if (map[val]) count += map[val];
            map[val] = (map[val] || 0) + 1;
        }
        console.log(count);
        rl.close();
    }
});
