const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, xStr] = lines[0].split(/\s+/).map(Number);
        const arr = lines[1].split(/\s+/).map(Number);
        const x = parseInt(xStr);
        for(let i=0; i<n; i++) {
            if(arr[i]===x) { console.log(i); rl.close(); return; }
            if(i>0 && arr[i-1]===x) { console.log(i-1); rl.close(); return; }
            if(i<n-1 && arr[i+1]===x) { console.log(i+1); rl.close(); return; }
        }
        console.log(-1);
        rl.close();
    }
});
