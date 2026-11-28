const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let last = arr[n-1];
        for(let i=n-1; i>0; i--) arr[i] = arr[i-1];
        arr[0] = last;
        console.log(arr.join(" "));
        rl.close();
    }
});
