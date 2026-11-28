const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        const arr1 = lines[1].split(/\s+/).map(Number);
        const order = lines[2].split(/\s+/).map(Number);
        
        let rank = {};
        order.forEach((x, i) => rank[x] = i);
        
        arr1.sort((a, b) => {
            let ra = rank[a] !== undefined ? rank[a] : Infinity;
            let rb = rank[b] !== undefined ? rank[b] : Infinity;
            if (ra !== rb) return ra - rb;
            return a - b;
        });
        console.log(arr1.join(" "));
        rl.close();
    }
});
