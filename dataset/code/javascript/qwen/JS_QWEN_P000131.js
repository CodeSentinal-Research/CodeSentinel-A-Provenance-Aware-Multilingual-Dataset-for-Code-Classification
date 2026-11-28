const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let leaders = [];
        let maxRight = arr[n-1];
        leaders.push(maxRight);
        for(let i=n-2; i>=0; i--) {
            if(arr[i] >= maxRight) {
                maxRight = arr[i];
                leaders.push(maxRight);
            }
        }
        console.log(leaders.reverse().join(" "));
        rl.close();
    }
});
