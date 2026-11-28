const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        let count = {};
        for(let x of nums) count[x] = (count[x]||0) + 1;
        
        let heap = [];
        Object.keys(count).forEach(key => {
            heap.push([parseInt(key), count[key]]);
        });
        
        // Sort by frequency desc, then value asc
        heap.sort((a,b) => b[1] - a[1] || a[0] - b[0]);
        
        let res = heap.slice(0, k).map(x => x[0]);
        console.log(res.join(" "));
        rl.close();
    }
});
