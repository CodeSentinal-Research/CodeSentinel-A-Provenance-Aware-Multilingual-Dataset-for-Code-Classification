const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        let even = 0, odd = 0;
        for(let num of nums) {
            let newEven = Math.max(even, odd+num);
            let newOdd = Math.max(odd, even-num);
            even = newEven;
            odd = newOdd;
        }
        console.log(Math.max(even, odd));
        rl.close();
    }
});
