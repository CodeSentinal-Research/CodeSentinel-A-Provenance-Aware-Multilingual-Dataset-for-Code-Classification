const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, target] = lines[0].split(/\s+/).map(Number);
        const arr = lines[1].split(/\s+/).map(Number);
        let count = 0;
        let map = {};
        for(let x of arr) {
            if(map[target-x]) count += map[target-x];
            map[x] = (map[x]||0)+1;
        }
        console.log(count);
        rl.close();
    }
});
