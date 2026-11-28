const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(String);
        
        nums.sort((a,b) => (b+a).localeCompare(a+b));
        console.log(nums.join('').replace(/^0+/, '') || '0');
        rl.close();
    }
});
