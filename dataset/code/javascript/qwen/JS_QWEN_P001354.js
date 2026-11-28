const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        
        function selectionSort(arr, i) {
            if(i===n) return;
            let minIdx = i;
            for(let j=i+1; j<n; j++) {
                if(arr[j]<arr[minIdx]) minIdx=j;
            }
            [arr[i], arr[minIdx]] = [arr[minIdx], arr[i]];
            selectionSort(arr, i+1);
        }
        selectionSort(arr, 0);
        console.log(arr.join(" "));
        rl.close();
    }
});
