const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2 + parseInt(lines[2])) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        const q = parseInt(lines[2]);
        
        let prefixXor = [0];
        for (let x of nums) prefixXor.push(prefixXor[prefixXor.length - 1] ^ x);
        
        let res = [];
        for (let i = 3; i < 3 + q; i++) {
            const [l, r] = lines[i].split(/\s+/).map(Number);
            res.push(prefixXor[r + 1] ^ prefixXor[l]);
        }
        console.log(res.join("\n"));
        rl.close();
    }
});
