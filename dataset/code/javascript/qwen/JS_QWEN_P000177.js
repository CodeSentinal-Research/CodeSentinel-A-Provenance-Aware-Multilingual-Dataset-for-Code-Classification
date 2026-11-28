const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k, target] = lines[0].split(/\s+/).map(Number);
        const arr = lines[1].split(/\s+/).map(Number);
        let idx = arr.findIndex(x => x >= target);
        if(idx === -1) idx = n;
        let l = idx-1, r = idx;
        let res = [];
        while(res.length < k) {
            if(l<0) res.push(arr[r++]);
            else if(r>=n) res.push(arr[l--]);
            else if(target-arr[l] <= arr[r]-target) res.push(arr[l--]);
            else res.push(arr[r++]);
        }
        console.log(res.sort((a,b)=>a-b).join(" "));
        rl.close();
    }
});
