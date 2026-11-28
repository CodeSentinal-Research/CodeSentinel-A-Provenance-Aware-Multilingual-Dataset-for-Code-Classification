const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, target] = lines[0].split(/\s+/).map(Number);
        const arr = lines[1].split(/\s+/).map(Number);
        let count = 0;
        for(let i=0; i<n-2; i++) {
            for(let j=i+1; j<n-1; j++) {
                for(let k=j+1; k<n; k++) {
                    if(arr[i]+arr[j]+arr[k]===target) count++;
                }
            }
        }
        console.log(count);
        rl.close();
    }
});
