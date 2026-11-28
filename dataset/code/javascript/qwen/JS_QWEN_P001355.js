const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        
        function insertionSort(arr, i) {
            if(i===n) return;
            let key = arr[i];
            let j = i-1;
            while(j>=0 && arr[j]>key) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
            insertionSort(arr, i+1);
        }
        insertionSort(arr, 1);
        console.log(arr.join(" "));
        rl.close();
    }
});
