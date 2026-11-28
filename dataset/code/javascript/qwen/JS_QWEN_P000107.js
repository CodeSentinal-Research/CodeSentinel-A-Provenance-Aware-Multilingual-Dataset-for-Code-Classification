const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let sorted = true;
        for(let i=1; i<n; i++) {
            if(arr[i] < arr[i-1]) { sorted = false; break; }
        }
        console.log(sorted ? "Sorted" : "Not Sorted");
        rl.close();
    }
});
