const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, target] = lines[0].split(/\s+/).map(Number);
        const arr = lines[1].split(/\s+/).map(Number);
        let map = {};
        for(let i=0; i<n; i++) {
            if(map[target - arr[i]] !== undefined) {
                console.log(`${map[target - arr[i]]} ${i}`);
                rl.close();
                return;
            }
            map[arr[i]] = i;
        }
        rl.close();
    }
});
