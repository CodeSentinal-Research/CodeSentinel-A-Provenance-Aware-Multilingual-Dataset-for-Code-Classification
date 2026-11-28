const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        function findMin(arr, n) {
            if (n === 1) return arr[0];
            return Math.min(arr[n - 1], findMin(arr, n - 1));
        }
        console.log(findMin(arr, n));
        rl.close();
    }
});
