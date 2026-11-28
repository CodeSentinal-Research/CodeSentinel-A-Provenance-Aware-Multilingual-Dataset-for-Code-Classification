const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const text = lines[0], broken = lines[1];
        let set = new Set(broken.split(''));
        let count = 0;
        for(let w of text.split(/\s+/)) {
            let valid = true;
            for(let c of w) if(set.has(c)) { valid=false; break; }
            if(valid) count++;
        }
        console.log(count);
        rl.close();
    }
});
