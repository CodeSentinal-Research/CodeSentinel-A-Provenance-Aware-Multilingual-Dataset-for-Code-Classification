const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let count = {};
        let maxF = 0, el = arr[0];
        arr.forEach(x => {
            count[x] = (count[x]||0)+1;
            if(count[x] > maxF || (count[x] === maxF && x < el)) {
                maxF = count[x];
                el = x;
            }
        });
        console.log(el);
        rl.close();
    }
});
