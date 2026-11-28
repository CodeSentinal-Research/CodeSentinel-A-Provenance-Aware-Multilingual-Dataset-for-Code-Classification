const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+2) {
        const n = parseInt(lines[0]);
        const budget = parseFloat(lines[1]);
        let found = false;
        for(let i=2; i<2+n; i++) {
            let [fid, price, avail] = lines[i].split(/\s+/);
            if(parseFloat(price) <= budget && avail === "Available") { console.log(fid); found=true; }
        }
        if(!found) console.log("No Flights Found");
        rl.close();
    }
});
