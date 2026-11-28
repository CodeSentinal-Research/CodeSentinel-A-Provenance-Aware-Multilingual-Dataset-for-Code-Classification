const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const words = lines[0].split(/\s+/);
        const s = lines[1];
        let count = 0;
        for(let w of words) if(s.startsWith(w)) count++;
        console.log(count);
        rl.close();
    }
});
