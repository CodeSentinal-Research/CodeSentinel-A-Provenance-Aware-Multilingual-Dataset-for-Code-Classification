const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let peak = 0;
        if(n===1) peak=0;
        else if(arr[0]>=arr[1]) peak=0;
        else if(arr[n-1]>=arr[n-2]) peak=n-1;
        else {
            for(let i=1; i<n-1; i++) {
                if(arr[i]>=arr[i-1] && arr[i]>=arr[i+1]) { peak=i; break; }
            }
        }
        console.log(peak);
        rl.close();
    }
});
