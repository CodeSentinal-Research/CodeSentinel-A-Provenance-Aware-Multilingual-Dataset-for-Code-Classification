const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, xStr] = lines[0].split(/\s+/).map(Number);
        const arr = lines[1].split(/\s+/).map(Number);
        const x = parseInt(xStr);
        let l=0, r=n-1, pos=n;
        while(l<=r) {
            let m = Math.floor((l+r)/2);
            if(arr[m]>=x) { pos=m; r=m-1; }
            else l=m+1;
        }
        console.log(pos);
        rl.close();
    }
});
