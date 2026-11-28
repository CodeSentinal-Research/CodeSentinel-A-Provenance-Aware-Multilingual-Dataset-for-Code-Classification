const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        const target = parseInt(lines[2]);
        function countOcc(arr, n, target) {
            if (n === 0) return 0;
            return (arr[n - 1] === target ? 1 : 0) + countOcc(arr, n - 1, target);
        }
        console.log(countOcc(arr, n, target));
        rl.close();
    }
});
