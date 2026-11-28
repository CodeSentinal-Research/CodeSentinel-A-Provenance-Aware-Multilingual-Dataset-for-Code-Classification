const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let passes = 0;
        let remaining = [...arr];
        while(remaining.length) {
            let next = [];
            let last = -Infinity;
            for(let x of remaining) {
                if(x > last) last = x;
                else next.push(x);
            }
            remaining = next;
            passes++;
        }
        console.log(passes);
        rl.close();
    }
});
