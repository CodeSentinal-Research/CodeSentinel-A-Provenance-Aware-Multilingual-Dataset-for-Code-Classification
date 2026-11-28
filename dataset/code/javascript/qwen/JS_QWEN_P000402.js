const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+2) {
        const n = parseInt(lines[0]);
        const dest = lines[1];
        let found = false;
        for(let i=2; i<2+n; i++) {
            let [fid, fdest] = lines[i].split(/\s+/);
            if(fdest === dest) { console.log(`${fid} ${fdest}`); found=true; }
        }
        if(!found) console.log("No Flights Found");
        rl.close();
    }
});
