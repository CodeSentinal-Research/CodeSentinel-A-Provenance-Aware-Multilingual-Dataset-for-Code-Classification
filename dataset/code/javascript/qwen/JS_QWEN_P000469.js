const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, xStr] = lines[0].split(/\s+/).map(Number);
        const arr = lines[1].split(/\s+/).map(Number);
        const x = parseInt(xStr);
        let closest = arr[0];
        for(let i=1; i<n; i++) {
            if(Math.abs(arr[i]-x) < Math.abs(closest-x)) closest=arr[i];
        }
        console.log(closest);
        rl.close();
    }
});
