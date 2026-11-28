const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        function isPal(arr, l, r) {
            if (l >= r) return true;
            if (arr[l] !== arr[r]) return false;
            return isPal(arr, l + 1, r - 1);
        }
        console.log(isPal(arr, 0, n - 1) ? "true" : "false");
        rl.close();
    }
});
