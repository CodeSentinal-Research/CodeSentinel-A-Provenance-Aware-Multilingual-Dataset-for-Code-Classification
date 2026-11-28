const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let first=-Infinity, second=-Infinity, third=-Infinity;
        for(let x of arr) {
            if(x>first) { third=second; second=first; first=x; }
            else if(x>second && x!==first) { third=second; second=x; }
            else if(x>third && x!==second && x!==first) { third=x; }
        }
        console.log(third === -Infinity ? first : third);
        rl.close();
    }
});
