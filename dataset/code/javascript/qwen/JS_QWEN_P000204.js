const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        arr.sort((a,b)=>a-b);
        for(let i=0; i<n-1; i+=2) {
            [arr[i], arr[i+1]] = [arr[i+1], arr[i]];
        }
        console.log(arr.join(" "));
        rl.close();
    }
});
