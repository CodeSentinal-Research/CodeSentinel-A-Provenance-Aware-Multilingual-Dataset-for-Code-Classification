const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        const p = parseInt(lines[2]);
        let total = arr.reduce((a,b)=>a+b, 0);
        if (total % p === 0) { console.log(0); rl.close(); return; }
        let target = total % p;
        let map = {}, sum = 0, minLen = n;
        for (let i = 0; i < n; i++) {
            sum = (sum + arr[i]) % p;
            let need = (sum - target + p) % p;
            if (map[need] !== undefined) minLen = Math.min(minLen, i - map[need]);
            map[sum] = i;
        }
        console.log(minLen === n ? -1 : minLen);
        rl.close();
    }
});
