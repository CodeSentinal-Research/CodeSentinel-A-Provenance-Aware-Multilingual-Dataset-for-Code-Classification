const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+2) {
        const n = parseInt(lines[0]);
        const id = lines[1];
        let found = false;
        for(let i=2; i<2+n; i++) {
            let [eid, name] = lines[i].split(/\s+/);
            if(eid === id) { console.log(`${eid} ${name}`); found=true; break; }
        }
        if(!found) console.log("Record Not Found");
        rl.close();
    }
});
