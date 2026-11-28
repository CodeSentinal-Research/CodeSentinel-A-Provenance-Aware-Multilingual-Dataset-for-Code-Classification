const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+2) {
        const n = parseInt(lines[0]);
        const hid = lines[1];
        let found = false;
        for(let i=2; i<2+n; i++) {
            let [ehid, name] = lines[i].split(/\s+/);
            if(ehid === hid) { console.log(`${ehid} ${name}`); found=true; break; }
        }
        if(!found) console.log("Hotel Not Found");
        rl.close();
    }
});
