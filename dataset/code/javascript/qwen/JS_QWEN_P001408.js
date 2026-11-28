const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let half = [...nums];
        half.sort((a,b)=>a-b);
        let res = new Array(n);
        let l = 0, r = Math.floor(n/2);
        if (n%2!==0) r++;
        
        for (let i = 0; i < n; i+=2) {
            res[i] = half[l++];
            if (i+1 < n) res[i+1] = half[r++];
        }
        console.log(res.join(" "));
        rl.close();
    }
});
