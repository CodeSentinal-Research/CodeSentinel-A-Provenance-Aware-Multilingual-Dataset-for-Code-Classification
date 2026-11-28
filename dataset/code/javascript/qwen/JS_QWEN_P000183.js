const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const arr = lines[1].split(/\s+/).map(Number);
        let map = {}, res = [];
        for(let i=0; i<k; i++) map[arr[i]] = (map[arr[i]]||0)+1;
        res.push(Object.keys(map).length);
        for(let i=k; i<n; i++) {
            map[arr[i]] = (map[arr[i]]||0)+1;
            map[arr[i-k]]--;
            if(map[arr[i-k]]===0) delete map[arr[i-k]];
            res.push(Object.keys(map).length);
        }
        console.log(res.join(" "));
        rl.close();
    }
});
