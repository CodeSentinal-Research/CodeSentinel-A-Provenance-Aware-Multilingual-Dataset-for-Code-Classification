const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let total = arr.reduce((a,b)=>a+b,0);
        let left=0;
        for(let i=0; i<n; i++) {
            if(left === total-left-arr[i]) { console.log(i); rl.close(); return; }
            left+=arr[i];
        }
        console.log(-1);
        rl.close();
    }
});
