const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const s = lines[0];
        const c = lines[1];
        
        let idx = s.indexOf(c);
        if (idx === -1) console.log(s);
        else {
            let prefix = s.substring(0, idx + 1).split('').reverse().join('');
            console.log(prefix + s.substring(idx + 1));
        }
        rl.close();
    }
});
