const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+1) {
        const n = parseInt(lines[0]);
        let strs = [];
        for(let i=1; i<=n; i++) strs.push(lines[i]);
        let prefix = strs[0];
        for(let i=1; i<n; i++) {
            while(!strs[i].startsWith(prefix)) prefix = prefix.slice(0,-1);
            if(!prefix) break;
        }
        console.log(prefix);
        rl.close();
    }
});
