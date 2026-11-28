const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const houses = lines[0].split(/\s+/).map(Number).sort((a,b)=>a-b);
        const heaters = lines[1].split(/\s+/).map(Number).sort((a,b)=>a-b);
        let maxR = 0;
        for (let h of houses) {
            let l = 0, r = heaters.length - 1;
            while (l < r) {
                let m = Math.floor((l + r) / 2);
                if (heaters[m] < h) l = m + 1;
                else r = m;
            }
            let d1 = Math.abs(heaters[l] - h);
            let d2 = l > 0 ? Math.abs(heaters[l - 1] - h) : Infinity;
            maxR = Math.max(maxR, Math.min(d1, d2));
        }
        console.log(maxR);
        rl.close();
    }
});
