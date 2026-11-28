const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, target] = lines[0].split(/\s+/).map(Number);
        const arr = lines[1].split(/\s+/).map(Number);
        let l = 0, r = n - 1;
        while (l <= r) {
            let m = Math.floor((l + r) / 2);
            if (arr[m] === target) { console.log("true"); rl.close(); return; }
            if (arr[l] === arr[m] && arr[m] === arr[r]) { l++; r--; continue; }
            if (arr[l] <= arr[m]) {
                if (target >= arr[l] && target < arr[m]) r = m - 1;
                else l = m + 1;
            } else {
                if (target > arr[m] && target <= arr[r]) l = m + 1;
                else r = m - 1;
            }
        }
        console.log("false");
        rl.close();
    }
});
