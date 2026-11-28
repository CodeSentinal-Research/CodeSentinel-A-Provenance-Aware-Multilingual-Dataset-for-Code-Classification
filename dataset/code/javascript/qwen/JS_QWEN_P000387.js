const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+2) {
        const n = parseInt(lines[0]);
        const tid = lines[1];
        let found = false;
        for(let i=2; i<2+n; i++) {
            let [etid, amount] = lines[i].split(/\s+/);
            if(etid === tid) { console.log(`${etid} ${amount}`); found=true; break; }
        }
        if(!found) console.log("Transaction Not Found");
        rl.close();
    }
});
