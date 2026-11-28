const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        let tails = [];
        for(let num of nums) {
            let l=0, r=tails.length;
            while(l<r) {
                let m = Math.floor((l+r)/2);
                if(tails[m] < num) l=m+1;
                else r=m;
            }
            tails[l] = num;
        }
        console.log(tails.length);
        rl.close();
    }
});
