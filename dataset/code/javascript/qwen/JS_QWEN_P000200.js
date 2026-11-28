const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let xor = 0;
        arr.forEach(x => xor ^= x);
        let setBit = xor & -xor;
        let x=0, y=0;
        arr.forEach(num => {
            if(num & setBit) x ^= num;
            else y ^= num;
        });
        console.log(`${Math.min(x,y)} ${Math.max(x,y)}`);
        rl.close();
    }
});
