const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let total = arr.reduce((a,b)=>a+b, 0);
        let minDiff = Infinity;
        function tugOfWar(i, sum1, count1) {
            if (i === n) {
                if (Math.abs(count1 - (n - count1)) <= 1) {
                    minDiff = Math.min(minDiff, Math.abs(total - 2 * sum1));
                }
                return;
            }
            tugOfWar(i + 1, sum1 + arr[i], count1 + 1);
            tugOfWar(i + 1, sum1, count1);
        }
        tugOfWar(0, 0, 0);
        console.log(minDiff);
        rl.close();
    }
});
