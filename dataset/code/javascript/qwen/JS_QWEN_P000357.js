const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const s = lines[0], c = lines[1];
        let count = 0;
        for(let char of s) if(char===c) count++;
        console.log(count);
        rl.close();
    }
});
