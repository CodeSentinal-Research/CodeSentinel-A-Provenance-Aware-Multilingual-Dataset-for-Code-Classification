const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const note = lines[0], mag = lines[1];
        let count = {};
        for(let c of mag) count[c]=(count[c]||0)+1;
        for(let c of note) {
            if(!count[c]) { console.log("No"); rl.close(); return; }
            count[c]--;
        }
        console.log("Yes");
        rl.close();
    }
});
