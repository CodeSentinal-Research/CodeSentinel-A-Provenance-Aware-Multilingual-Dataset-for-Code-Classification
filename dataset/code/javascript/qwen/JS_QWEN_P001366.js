const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        
        function quickSort(arr, low, high) {
            if(low<high) {
                let pi = partition(arr, low, high);
                quickSort(arr, low, pi-1);
                quickSort(arr, pi+1, high);
            }
        }
        function partition(arr, low, high) {
            let pivot = arr[high];
            let i = low-1;
            for(let j=low; j<high; j++) {
                if(arr[j]<=pivot) {
                    i++;
                    [arr[i], arr[j]] = [arr[j], arr[i]];
                }
            }
            [arr[i+1], arr[high]] = [arr[high], arr[i+1]];
            return i+1;
        }
        quickSort(arr, 0, n-1);
        console.log(arr.join(" "));
        rl.close();
    }
});
