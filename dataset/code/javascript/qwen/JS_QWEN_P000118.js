const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let j = 0;
        for(let i=0; i<n; i++) {
            if(arr[i] !== 0) {
                arr[j++] = arr[i];
            }
        }
        while(j < n) arr[j++] = 0;
        console.log(arr.join(" "));
        rl.close();
    }
});
