const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+2) {
        const n = parseInt(lines[0]);
        const name = lines[1].toLowerCase();
        let found = false;
        for(let i=2; i<2+n; i++) {
            let cname = lines[i].toLowerCase();
            if(cname === name) { console.log(lines[i]); found=true; }
        }
        if(!found) console.log("No Contacts Found");
        rl.close();
    }
});
