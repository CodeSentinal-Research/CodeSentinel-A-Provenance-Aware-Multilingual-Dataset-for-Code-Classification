const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, xStr] = lines[0].split(/\s+/).map(Number);
        const arr = lines[1].split(/\s+/).map(Number);
        const x = parseInt(xStr);
        let peak = 0;
        for(let i=1; i<n-1; i++) if(arr[i]>arr[i-1] && arr[i]>arr[i+1]) { peak=i; break; }
        let l=0, r=peak;
        while(l<=r) {
            let m = Math.floor((l+r)/2);
            if(arr[m]===x) { console.log(m); rl.close(); return; }
            else if(arr[m]<x) l=m+1;
            else r=m-1;
        }
        l=peak; r=n-1;
        while(l<=r) {
            let m = Math.floor((l+r)/2);
            if(arr[m]===x) { console.log(m); rl.close(); return; }
            else if(arr[m]>x) l=m+1;
            else r=m-1;
        }
        console.log(-1);
        rl.close();
    }
});
