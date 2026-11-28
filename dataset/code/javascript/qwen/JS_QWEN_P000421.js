const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+2) {
        const n = parseInt(lines[0]);
        const currDate = lines[1];
        let found = false;
        for(let i=2; i<2+n; i++) {
            let [mid, expDate] = lines[i].split(/\s+/);
            if(expDate < currDate) { console.log(mid); found=true; }
        }
        if(!found) console.log("No Expired Memberships");
        rl.close();
    }
});
