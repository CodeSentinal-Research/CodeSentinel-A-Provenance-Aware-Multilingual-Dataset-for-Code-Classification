const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let count = {}, maxEl = arr[0], maxCount = 0;
        arr.forEach(x => {
            count[x] = (count[x] || 0) + 1;
            if(count[x] > maxCount) { maxCount = count[x]; maxEl = x; }
        });
        console.log(maxCount > n/2 ? maxEl : -1); // Simplified majority check
        rl.close();
    }
});
