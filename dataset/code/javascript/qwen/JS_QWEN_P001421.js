const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        let list1 = [];
        for (let i = 1; i <= n; i++) list1.push(lines[i]);
        
        const m = parseInt(lines[n+1]);
        let list2 = [];
        for (let i = n + 2; i < n + 2 + m; i++) list2.push(lines[i]);
        
        let map1 = {}, map2 = {};
        list1.forEach((s, i) => map1[s] = i);
        list2.forEach((s, i) => map2[s] = i);
        
        let minSum = Infinity;
        let res = [];
        for (let s in map1) {
            if (map2[s] !== undefined) {
                let sum = map1[s] + map2[s];
                if (sum < minSum) {
                    minSum = sum;
                    res = [s];
                } else if (sum === minSum) {
                    res.push(s);
                }
            }
        }
        console.log(res.sort().join("\n"));
        rl.close();
    }
});
