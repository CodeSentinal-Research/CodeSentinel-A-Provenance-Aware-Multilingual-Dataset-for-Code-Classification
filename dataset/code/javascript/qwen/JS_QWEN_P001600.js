const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        const q = parseInt(lines[2]);
        
        let prefix = [0];
        for (let num of nums) prefix.push(prefix[prefix.length - 1] + num);
        
        let res = [];
        for (let i = 3; i < 3 + q; i++) {
            const [l, r] = lines[i].split(/\s+/).map(Number);
            let sum = prefix[r + 1] - prefix[l];
            let len = r - l + 1;
            res.push((sum / len).toFixed(2));
        }
        
        console.log(res.join("\n"));
        rl.close();
    }
});
