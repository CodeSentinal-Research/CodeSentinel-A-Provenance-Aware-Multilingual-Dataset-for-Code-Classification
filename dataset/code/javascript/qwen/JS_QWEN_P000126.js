const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, target] = lines[0].split(/\s+/).map(Number);
        const arr = lines[1].split(/\s+/).map(Number);
        arr.sort((a,b) => a-b);
        let closest = arr[0]+arr[1]+arr[2];
        for(let i=0; i<n-2; i++) {
            let l=i+1, r=n-1;
            while(l<r) {
                let sum = arr[i]+arr[l]+arr[r];
                if(Math.abs(sum-target) < Math.abs(closest-target)) closest = sum;
                if(sum < target) l++;
                else r--;
            }
        }
        console.log(closest);
        rl.close();
    }
});
