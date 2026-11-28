const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+2) {
        const n = parseInt(lines[0]);
        const bg = lines[1];
        let found = false;
        for(let i=2; i<2+n; i++) {
            let [pid, pbg] = lines[i].split(/\s+/);
            if(pbg === bg) { console.log(pid); found=true; }
        }
        if(!found) console.log("No Patients Found");
        rl.close();
    }
});
