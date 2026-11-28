const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+1) {
        const n = parseInt(lines[0]);
        let strs = [];
        for(let i=1; i<=n; i++) strs.push(lines[i]);
        let map = {};
        strs.forEach(s => {
            let key = s.split('').sort().join('');
            if(!map[key]) map[key]=[];
            map[key].push(s);
        });
        for(let k in map) console.log(map[k].join(" "));
        rl.close();
    }
});
