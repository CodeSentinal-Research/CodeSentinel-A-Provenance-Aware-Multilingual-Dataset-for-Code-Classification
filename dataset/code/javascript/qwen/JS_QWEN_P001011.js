const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        // Heap Sort
        function heapify(a, n, i) {
            let largest = i;
            let l = 2 * i + 1, r = 2 * i + 2;
            if (l < n && a[l] > a[largest]) largest = l;
            if (r < n && a[r] > a[largest]) largest = r;
            if (largest !== i) {
                [a[i], a[largest]] = [a[largest], a[i]];
                heapify(a, n, largest);
            }
        }
        for (let i = Math.floor(n / 2) - 1; i >= 0; i--) heapify(arr, n, i);
        for (let i = n - 1; i > 0; i--) {
            [arr[0], arr[i]] = [arr[i], arr[0]];
            heapify(arr, i, 0);
        }
        console.log(arr.join(" "));
        rl.close();
    }
});
