const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let res = new Array(n).fill(0);
        for(let i=0; i<n; i++) {
            let count = 0;
            for(let j=i+1; j<n; j++) if(arr[j]<arr[i]) count++;
            res[i] = count;
        }
        console.log(res.join(" "));
        rl.close();
    }
});
