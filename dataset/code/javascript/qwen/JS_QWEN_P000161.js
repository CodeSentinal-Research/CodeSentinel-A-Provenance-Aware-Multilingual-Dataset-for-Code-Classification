const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, target] = lines[0].split(/\s+/).map(Number);
        const arr = lines[1].split(/\s+/).map(Number);
        let pairs = [];
        for(let i=0; i<n; i++) {
            for(let j=i+1; j<n; j++) {
                if(arr[i]+arr[j]===target) pairs.push(`(${arr[i]}, ${arr[j]})`);
            }
        }
        console.log(pairs.join(" "));
        rl.close();
    }
});
