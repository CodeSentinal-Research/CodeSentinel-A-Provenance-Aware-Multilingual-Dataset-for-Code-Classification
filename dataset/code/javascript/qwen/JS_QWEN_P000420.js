const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+1) {
        const n = parseInt(lines[0]);
        let found = false;
        for(let i=1; i<=n; i++) {
            let [sid, status] = lines[i].split(/\s+/);
            if(status === "Vacant") { console.log(sid); found=true; }
        }
        if(!found) console.log("No Slots Available");
        rl.close();
    }
});
