const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let d = arr[1]-arr[0];
        for(let i=1; i<n-1; i++) {
            if(arr[i+1]-arr[i] !== d) { console.log(arr[i]+d); rl.close(); return; }
        }
        rl.close();
    }
});
