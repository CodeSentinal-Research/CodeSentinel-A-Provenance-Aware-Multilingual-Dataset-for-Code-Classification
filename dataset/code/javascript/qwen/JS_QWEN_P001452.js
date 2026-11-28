const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, q] = lines[0].split(/\s+/).map(Number);
        let arr = lines[1].split(/\s+/).map(Number);
        let count = {};
        for (let x of arr) count[x] = (count[x] || 0) + 1;
        let distinct = Object.keys(count).length;
        
        let res = [];
        for (let i = 2; i < 2 + q; i++) {
            const [idx, val] = lines[i].split(/\s+/).map(Number);
            let old = arr[idx - 1];
            arr[idx - 1] = val;
            
            count[old]--;
            if (count[old] === 0) distinct--;
            delete count[old];
            
            count[val] = (count[val] || 0) + 1;
            if (count[val] === 1) distinct++;
            
            res.push(distinct);
        }
        console.log(res.join("\n"));
        rl.close();
    }
});
