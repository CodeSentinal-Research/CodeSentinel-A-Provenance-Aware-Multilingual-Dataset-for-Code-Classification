const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, hStr] = lines[0].split(/\s+/).map(Number);
        const piles = lines[1].split(/\s+/).map(Number);
        const h = parseInt(hStr);
        let l=1, r=Math.max(...piles);
        while(l<r) {
            let mid = Math.floor((l+r)/2);
            let hours = piles.reduce((acc, p) => acc + Math.ceil(p/mid), 0);
            if(hours>h) l=mid+1;
            else r=mid;
        }
        console.log(l);
        rl.close();
    }
});
