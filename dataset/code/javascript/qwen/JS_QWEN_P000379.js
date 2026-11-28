const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+2) {
        const n = parseInt(lines[0]);
        const tnum = lines[1];
        let found = false;
        for(let i=2; i<2+n; i++) {
            let [etnum, route] = lines[i].split(/\s+/);
            if(etnum === tnum) { console.log(`${etnum} ${route}`); found=true; break; }
        }
        if(!found) console.log("Train Not Found");
        rl.close();
    }
});
