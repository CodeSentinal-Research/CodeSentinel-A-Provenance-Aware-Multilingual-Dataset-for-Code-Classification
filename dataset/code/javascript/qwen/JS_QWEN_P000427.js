const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+2) {
        const n = parseInt(lines[0]);
        const minPrice = parseFloat(lines[1]);
        let found = false;
        for(let i=2; i<2+n; i++) {
            let [pname, price] = lines[i].split(/\s+/);
            if(parseFloat(price) >= minPrice) { console.log(pname); found=true; }
        }
        if(!found) console.log("No Eligible Products");
        rl.close();
    }
});
