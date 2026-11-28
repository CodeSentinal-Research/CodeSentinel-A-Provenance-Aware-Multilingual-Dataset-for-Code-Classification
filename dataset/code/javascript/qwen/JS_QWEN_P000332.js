const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const order = lines[0], s = lines[1];
        let count = {};
        for(let c of s) count[c]=(count[c]||0)+1;
        let res = "";
        for(let c of order) {
            if(count[c]) { res += c.repeat(count[c]); delete count[c]; }
        }
        for(let c in count) res += c.repeat(count[c]);
        console.log(res);
        rl.close();
    }
});
