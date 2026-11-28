const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, xStr] = lines[0].split(/\s+/).map(Number);
        const arr = lines[1].split(/\s+/).map(Number);
        const x = parseInt(xStr);
        let l=0, r=n-1, closest=arr[0];
        while(l<=r) {
            let m = Math.floor((l+r)/2);
            if(Math.abs(arr[m]-x) < Math.abs(closest-x)) closest=arr[m];
            if(arr[m]<x) l=m+1;
            else r=m-1;
        }
        console.log(closest);
        rl.close();
    }
});
