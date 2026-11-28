const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const stations = lines[1].split(/\s+/).map(Number);
        
        let l = 0, r = stations[n-1] - stations[0];
        for (let i = 0; i < 100; i++) {
            let mid = (l + r) / 2;
            let count = 0;
            for (let j = 1; j < n; j++) {
                count += Math.floor((stations[j] - stations[j-1]) / mid);
            }
            if (count > k) l = mid;
            else r = mid;
        }
        console.log(l.toFixed(6));
        rl.close();
    }
});
