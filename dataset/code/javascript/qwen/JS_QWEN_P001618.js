const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let prefixXor = [0];
        for (let x of nums) prefixXor.push(prefixXor[prefixXor.length - 1] ^ x);
        console.log(prefixXor.slice(1).join(" "));
        rl.close();
    }
});
