const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, trips] = lines[0].split(/\s+/).map(Number);
        const times = lines[1].split(/\s+/).map(Number);
        
        let l=1, r=Math.min(...times)*trips;
        while(l<r) {
            let mid = Math.floor((l+r)/2);
            let t = 0;
            for(let time of times) t+=Math.floor(mid/time);
            if(t>=trips) r=mid;
            else l=mid+1;
        }
        console.log(l);
        rl.close();
    }
});
