const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let count = {};
        for (let x of nums) {
            let r = ((x % k) + k) % k;
            count[r] = (count[r] || 0) + 1;
        }
        
        let valid = true;
        if (count[0] % 2 !== 0) valid = false;
        for (let i = 1; i <= Math.floor(k/2); i++) {
            if ((count[i] || 0) !== (count[k-i] || 0)) valid = false;
        }
        console.log(valid ? "YES" : "NO");
        rl.close();
    }
});
