const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const target = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let l=0, r=1;
        while(arr[r] < target) { l=r; r*=2; if(r>=arr.length) { r=arr.length-1; break; } }
        while(l<=r) {
            let m = Math.floor((l+r)/2);
            if(arr[m]===target) { console.log(m); rl.close(); return; }
            else if(arr[m]<target) l=m+1;
            else r=m-1;
        }
        console.log(-1);
        rl.close();
    }
});
