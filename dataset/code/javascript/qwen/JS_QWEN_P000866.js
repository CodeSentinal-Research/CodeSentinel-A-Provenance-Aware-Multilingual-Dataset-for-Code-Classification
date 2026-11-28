const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, q] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        let prefix = [0];
        for (let x of nums) prefix.push(prefix[prefix.length-1] ^ x);
        
        let res = [];
        for (let i = 2; i < 2 + q; i++) {
            const [l, r] = lines[i].split(/\s+/).map(Number);
            res.push(prefix[r+1] ^ prefix[l]);
        }
        console.log(res.join("\n"));
        rl.close();
    }
});
