const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+2) {
        const n = parseInt(lines[0]);
        const status = lines[1];
        let found = false;
        for(let i=2; i<2+n; i++) {
            let [oid, ostatus] = lines[i].split(/\s+/);
            if(ostatus === status) { console.log(`${oid} ${ostatus}`); found=true; }
        }
        if(!found) console.log("No Orders Found");
        rl.close();
    }
});
