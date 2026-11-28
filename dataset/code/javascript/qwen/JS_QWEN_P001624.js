const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const diff = lines[1].split(/\s+/).map(Number);
        
        let arr = [diff[0]];
        for (let i = 1; i < n; i++) {
            arr.push(arr[i-1] + diff[i]);
        }
        console.log(arr.join(" "));
        rl.close();
    }
});
