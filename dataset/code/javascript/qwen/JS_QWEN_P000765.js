const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        function isMaxHeap(arr, i, n) {
            if (i >= (n - 1) / 2) return true;
            let left = 2 * i + 1, right = 2 * i + 2;
            if (left < n && arr[i] < arr[left]) return false;
            if (right < n && arr[i] < arr[right]) return false;
            return isMaxHeap(arr, left, n) && isMaxHeap(arr, right, n);
        }
        console.log(isMaxHeap(arr, 0, n) ? "true" : "false");
        rl.close();
    }
});
