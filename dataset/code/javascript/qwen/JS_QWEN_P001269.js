const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let count = {};
        for(let x of nums) count[x]=(count[x]||0)+1;
        
        let keys = Object.keys(count).map(Number);
        let valid = true;
        for(let k_val of keys) {
            if(count[k_val]%k !== 0) { valid=false; break; }
        }
        console.log(valid ? "YES" : "NO");
        rl.close();
    }
});
