const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        
        function bubbleSort(arr, n) {
            if (n === 1) return;
            for (let i = 0; i < n-1; i++) {
                if (arr[i] > arr[i+1]) [arr[i], arr[i+1]] = [arr[i+1], arr[i]];
            }
            bubbleSort(arr, n-1);
        }
        bubbleSort(arr, n);
        console.log(arr.join(" "));
        rl.close();
    }
});
